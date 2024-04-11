/*
    author:  Maksim1744
    created: 13.11.2020 17:37:55
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

int a[1050];

int comp(const int* a, const int *b) {
    if (*a < *b) return -1;
    if (*a > *b) return 1;
    return 0;
}

void test_case() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof (int), (int(*) (const void *, const void *)) comp);
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] == a[i + 1]) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        test_case();
    }
    return 0;
}