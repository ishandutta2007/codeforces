#include <iostream>
#include <cstdio>
using namespace std;

const int N = 20005, M = 55, P = 100, INF = 1E9;

int n, m, p, a[N];
long long dp[2][M][P], f[N][M];

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            f[i][j] = -INF;
    for (int j = 0; j < m; j++)
        fill(dp[0][j], dp[0][j] + p, -INF);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int cur = i & 1, pre = cur ^ 1;
        for (int j = 0; j < m; j++)
        {
            fill(dp[cur][j], dp[cur][j] + p, -INF);
            dp[cur][j][a[i] % p] = max(dp[cur][j][a[i] % p], f[i - 1][j]);
            for (int k = 0; k < p; k++)
                dp[cur][j][(k + a[i]) % p] = max(dp[cur][j][(k + a[i]) % p], dp[pre][j][k]);
            for (int k = 0; k < p; k++)
                f[i][j + 1] = max(f[i][j + 1], dp[cur][j][k] + k);
        }
    }
    printf("%I64d\n", f[n][m]);
}