/*
    author:  Maksim1744
    created: 23.10.2020 01:55:42
*/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

#define N 1005

int main() {
    int d[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            d[i][j] = 2000000;
        }
        d[i][i] = 0;
    }
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    int es[N][2];

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        int w;
        scanf("%d", &w);
        d[a][b] = min(d[a][b], w);
        d[b][a] = min(d[b][a], w);
        es[i][0] = a;
        es[i][1] = b;
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    int pt[N][2];
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &pt[i][0], &pt[i][1]);
        --pt[i][0]; --pt[i][1];
    }

    int ans = 2e9;
    for (int i = 0; i < m; ++i) {
        int cur = 0;
        for (int j = 0; j < k; ++j) {
            cur += min(d[pt[j][0]][pt[j][1]], min(d[pt[j][0]][es[i][0]] + d[es[i][1]][pt[j][1]], d[pt[j][0]][es[i][1]] + d[es[i][0]][pt[j][1]]));
        }
        ans = min(ans, cur);
    }
    printf("%d\n", ans);
    return 0;
}