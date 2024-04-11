/*
    author:  Maksim1744
    created: 27.10.2020 17:59:56
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

int inf = 2000000000;
int a[500050];
int can_change[500050];
int at[500050];
int atu[500050];
int compa[500050];
int last[500050];

int comp(const int *a, const int *b) {
    if (*a < *b) return -1;
    if (*a == *b) return 0;
    return 1;
}

int calc(int l, int r) {
    for (int i = 0; i < r - l + 1; ++i) {
        at[i] = a[l + i];
    }
    // printf("-----------------\n");
    // for (int i = 0; i < r - l + 1; ++i) {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < r - l + 1; ++i) {
    //     printf("%d ", at[i]);
    // }
    // printf("\n");
    qsort(at, r - l + 1, sizeof(int), (int(*)(const void*, const void*))comp);
    int iu = 0;
    for (int i = 0; i < r - l + 1; ++i) {
        if (i == 0 || at[i] != at[i - 1]) {
            atu[iu] = at[i];
            ++iu;
        }
    }
    for (int i = 0; i < r - l + 1; ++i) {
        int L = -1, R = iu;
        while (R - L > 1) {
            int c = (R + L) / 2;
            if (atu[c] <= a[l + i]) L = c;
            else R = c;
        }
        assert(a[l + i] == atu[L]);
        compa[i] = L;
    }
    for (int i = 0; i < r - l + 5; ++i) {
        last[i] = inf;
    }
    last[0] = 0;
    for (int i = 0; i < r - l + 1; ++i) {
        int k = compa[i];
        if (k < compa[0] || k > compa[r - l]) continue;
        int L = -1, R = r - l + 3;
        while (R - L > 1) {
            int C = (L + R) / 2;
            if (last[C] <= k) L = C;
            else R = C;
        }
        // printf("(%d, %d)\n", R, k);
        last[R] = k;
    }
    // for (int i = 0; i < r - l + 1; ++i) {
    //     printf("%d ", compa[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < r - l + 5; ++i) {
    //     printf("%d ", last[i]);
    // }
    // printf("\n");
    int ans = 0;
    for (int i = 0; i < r - l + 5; ++i) {
        if (last[i] == compa[r - l]) ans = max(ans, i);
    }
    // printf("%d\n=========\n", ans);
    return r - l + 1 - ans;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    a[0] = -inf;
    for (int i = 0; i < n + 2; ++i) {
        can_change[i] = 1;
    }
    can_change[0] = 0;
    can_change[n + 1] = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i + 1]);
    }
    a[n + 1] = inf;
    n += 2;
    for (int i = 0; i < k; ++i) {
        int b;
        scanf("%d", &b);
        can_change[b] = 0;
    }
    for (int i = 0; i < n; ++i) {
        a[i] -= i;
    }

    int ans = 0;

    int l = 0;
    while (l < n - 1) {
        int r = l + 1;
        while (can_change[r]) ++r;
        if (a[l] > a[r]) {
            printf("-1\n");
            return 0;
        }
        int cur = calc(l, r);
        // printf("%d %d %d\n", l, r, cur);
        ans += cur;
        l = r;
    }
    printf("%d\n", ans);

    return 0;
}