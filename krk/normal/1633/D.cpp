#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
const int Maxm = 12005;
const int Inf = 2000000000;

int nd[Maxn];
int T;
int n, k;
int dp[Maxn][Maxm];
int b[Maxn];
int c[Maxn];

int main()
{
    fill(nd, nd + Maxn, Inf);
    nd[1] = 0;
    for (int i = 1; i < Maxn; i++)
        for (int j = 1; j <= i; j++) if (i + i / j < Maxn)
            nd[i + i / j] = min(nd[i + i / j], nd[i] + 1);
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        fill((int*)dp, (int*)dp + (n + 1) * Maxm, -Inf);
        k = min(k, 12 * n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            b[i] = nd[b[i]];
        }
        for (int i = 0; i < n; i++)
            scanf("%d", &c[i]);
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= k; j++) if (dp[i][j] >= 0) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                if (j + b[i] <= k)
                    dp[i + 1][j + b[i]] = max(dp[i + 1][j + b[i]], dp[i][j] + c[i]);
            }
        int res = -Inf;
        for (int j = 0; j <= k; j++)
            res = max(res, dp[n][j]);
        printf("%d\n", res);
    }
    return 0;
}