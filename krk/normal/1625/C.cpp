#include <bits/stdc++.h>
using namespace std;

const int Inf = 2000000000;
const int Maxn = 505;

int n, l, k;
int d[Maxn];
int a[Maxn];
int cur, dp[2][Maxn][Maxn];

int main()
{
    fill((int*)dp, (int*)dp + 2 * Maxn * Maxn, Inf);
    scanf("%d %d %d", &n, &l, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &d[i]);
    d[n] = l;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    dp[cur][0][0] = (d[1] - d[0]) * a[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
            for (int l = 0; l <= i && l <= k; l++) if (dp[cur][j][l] >= 0) {
                int best = dp[cur][j][l]; dp[cur][j][l] = Inf;
                dp[!cur][i][l] = min(dp[!cur][i][l], best + (d[i + 1] - d[i]) * a[i]);
                if (l + 1 <= k)
                    dp[!cur][j][l + 1] = min(dp[!cur][j][l + 1], best + (d[i + 1] - d[i]) * a[j]);
            }
        cur = !cur;
    }
    int res = Inf;
    for (int j = 0; j < n; j++)
        for (int l = 0; l <= k; l++)
            res = min(res, dp[cur][j][l]);
    cout << res << endl;
    return 0;
}