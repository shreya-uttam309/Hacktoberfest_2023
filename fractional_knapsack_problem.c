#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int value;
};

int compare(const void *a, const void *b) {
    double ratioA = ((double)((struct Item*)a)->value / (double)((struct Item*)a)->weight);
    double ratioB = ((double)((struct Item*)b)->value / (double)((struct Item*)b)->weight);
    return (ratioB > ratioA) - (ratioB < ratioA);
}

double fractionalKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].value * ((double) remainingWeight / (double) items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    struct Item items[] = {{2, 10}, {3, 5}, {5, 15}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 5;

    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
