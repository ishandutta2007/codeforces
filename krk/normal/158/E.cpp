#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 4005;
const int Inf = 1000000000;

int n, k;
int t[Maxn], d[Maxn];
int dp[Maxn][Maxn], mn[Maxn][Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d %d", &t[i], &d[i]);
    t[n] = 86401; d[n] = 0;
    fill((int*)mn, (int*)mn + Maxn * Maxn, Inf);
    mn[0][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++) if (mn[i][j] != Inf) {
            dp[i + 1][j] = max(dp[i + 1][j], max(dp[i][j], t[i] - mn[i][j] > 0? t[i] - mn[i][j]: 0));
            dp[i + 1][j + 1] = dp[i][j];
            mn[i + 1][j] = min(mn[i + 1][j], max(mn[i][j], t[i]) + d[i]);
            mn[i + 1][j + 1] = min(mn[i + 1][j + 1], mn[i][j]);
        }
    int res = 0;
    for (int j = 0; j <= k; j++) res = max(res, dp[n + 1][j]);
    printf("%d\n", res);
    return 0;
}