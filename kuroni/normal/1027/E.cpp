#include <iostream>
#include <cstdio>
using namespace std;

const int N = 505,  MOD = 998244353;

int n, k;
long long ans = 0, f[2][N][N], g[N];

int main()
{
    scanf("%d%d", &n, &k);
    f[0][1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        int cur = i & 1, pre = cur ^ 1;
        for (int j = 1; j <= i; j++)
        {
            for (int k = 1; k <= j; k++)
                (f[cur][j][1] += f[pre][j][k]) %= MOD;
            for (int k = 2; k <= j; k++)
                (f[cur][j][k] += f[pre][j][k - 1] + (j == k ? f[pre][j - 1][k - 1] : 0)) %= MOD;
        }
        for (int j = 1; j <= i; j++)
            for (int k = 1; k <= j; k++)
                f[pre][j][k] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            (g[i] += f[n & 1][i][j]) %= MOD;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i * j < k)
                (ans += g[i] * g[j]) %= MOD;
    printf("%lld\n", ans * 2 % MOD);
}