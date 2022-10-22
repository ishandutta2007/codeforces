#include <bits/stdc++.h>
using namespace std;

const int Maxn = 252;
const int Maxm = 510;
const int nil = 255;
const int Inf = 1000000000;

int dp[Maxn][Maxn][Maxm];
int n, m;
int a[Maxn];

int main()
{
    fill((int*)dp, (int*)dp + Maxn * Maxn * Maxm, Inf);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    dp[0][Maxn - 1][nil] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < Maxn; j++)
            for (int k = 0; k < Maxm; k++) if (dp[i][j][k] < Inf) {
                int to = min(j, (Maxn - 1) / (i + 1));
                for (int z = 0; z <= to; z++) {
                    int nd = (k - nil) + a[i] - z;
                    if (abs(nd) >= Maxn) continue;
                    int cand = dp[i][j][k] + abs(nd);
                    dp[i + 1][z][nd + nil] = min(dp[i + 1][z][nd + nil], cand);
                }
            }
    int res = Inf;
    for (int j = 0; j < Maxn; j++)
        res = min(res, dp[n][j][nil]);
    printf("%d\n", res);
    return 0;
}