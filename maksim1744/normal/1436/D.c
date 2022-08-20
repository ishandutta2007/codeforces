/*
    author:  Maksim1744
    created: 24.10.2020 17:26:57
*/

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <inttypes.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

struct Vec {
    int size;
    int capacity;
    int *data;
};

struct Vec new_vec() {
    struct Vec v;
    v.size = 0;
    v.capacity = 1;
    v.data = (int*)calloc(1, sizeof(int));
    return v;
}

void add(struct Vec *v, int a) {
    if (v->size == v->capacity) {
        v->data = (int*)realloc(v->data, v->capacity * 2 * sizeof(int));
        v->capacity *= 2;
    }
    v->data[v->size] = a;
    v->size++;
}

struct Vec g[200020];
long long a[200020];

long long leafes[200020];
long long sm[200020];

long long ans = 0;

void dfs(int v) {
    if (g[v].size == 0) {
        leafes[v] = 1;
    }
    sm[v] = a[v];
    for (int i = 0; i < g[v].size; ++i) {
        int k = g[v].data[i];
        dfs(k);
        sm[v] += sm[k];
        leafes[v] += leafes[k];
    }
    ans = max(ans, (sm[v] + leafes[v] - 1) / leafes[v]);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        g[i] = new_vec();
    }

    for (int i = 0; i < n - 1; ++i) {
        int p;
        scanf("%d", &p);
        --p;
        add(&g[p], i + 1);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        leafes[i] = 0;
        sm[i] = 0;
    }
    // for (int i = 0; i < n; ++i) {
    //     printf("size = %d | ", g[i].size);
    //     for (int j = 0; j < g[i].size; ++j) {
    //         printf("%d, ", g[i].data[j]);
    //     }
    //     printf("\n");
    // }
    dfs(0);
    printf("%lld\n", ans);

    return 0;
}