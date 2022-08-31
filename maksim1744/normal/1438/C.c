/*
    author:  Maksim1744
    created: 13.11.2020 17:40:24
*/

#include <stdio.h>
#include <inttypes.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

void test_case() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int k;
            scanf("%d", &k);
            if (k % 2 != (i + j) % 2)
                k++;
            printf("%d ", k);
        }
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        test_case();
    }
    return 0;
}