#include <bits/stdc++.h>
using namespace std;

const int Maxn = 72;
const int Inf = 1000000000;

int n, m, k;
int B[Maxn][Maxn];
int dp[Maxn][Maxn][Maxn][Maxn];

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &B[i][j]);
    fill((int*)dp, (int*)dp + Maxn * Maxn * Maxn * Maxn, -Inf);
    dp[0][0][0][0] = 0;
    int lim = m / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            for (int l = 0; l <= lim; l++)
                for (int z = 0; z < k; z++) if (dp[i][j][l][z] >= 0) {
                    dp[i][j + 1][l][z] = max(dp[i][j + 1][l][z], dp[i][j][l][z]);
                    if (l + 1 <= lim)
                        dp[i][j + 1][l + 1][(z + B[i][j]) % k] = max(dp[i][j + 1][l + 1][(z + B[i][j]) % k],
                                                                     dp[i][j][l][z] + B[i][j]);
                }
        for (int l = 0; l <= lim; l++)
            for (int z = 0; z < k; z++)
                dp[i + 1][0][0][z] = max(dp[i + 1][0][0][z], dp[i][m][l][z]);
    }
    printf("%d\n", dp[n][0][0][0]);
    return 0;
}