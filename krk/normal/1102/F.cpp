#include <bits/stdc++.h>
using namespace std;

const int Maxn = 16;
const int Maxm = 10005;
const int Inf = 1000000007;

int n, m;
int B[Maxn][Maxm];
int nxt[Maxn][Maxn], clos[Maxn][Maxn];
int res;
int dp[1 << Maxn][Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &B[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int best1 = Inf, best2 = Inf;
            for (int k = 0; k < m; k++)
                best1 = min(best1, abs(B[i][k] - B[j][k]));
            for (int k = 0; k + 1 < m; k++)
                best2 = min(best2, abs(B[j][k] - B[i][k + 1]));
            nxt[i][j] = best1, clos[i][j] = best2;
        }
    for (int i = 0; i < n; i++) {
        fill((int*)dp, (int*)dp + (1 << Maxn) * Maxn, 0);
        dp[1 << i][i] = Inf;
        for (int j = 0; j < 1 << n; j++)
            for (int k = 0; k < n; k++) if (dp[j][k] > 0)
                for (int nk = 0; nk < n; nk++) if (!(j & 1 << nk)) {
                    int cand = min(dp[j][k], nxt[k][nk]);
                    dp[j | 1 << nk][nk] = max(dp[j | 1 << nk][nk], cand);
                }
        int all = (1 << n) - 1;
        for (int k = 0; k < n; k++)
            res = max(res, min(dp[all][k], clos[i][k]));
    }
    printf("%d\n", res);
    return 0;
}