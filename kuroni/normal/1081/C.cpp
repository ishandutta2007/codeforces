#include <iostream>
#include <cstdio>
using namespace std;

const int N = 2005, K = 2005, MOD = 998244353;

int n, m, k;
long long f[N][K];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    f[1][0] = m % MOD;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= i && j <= k; j++)
            f[i][j] = (f[i - 1][j] + (j > 0 ? f[i - 1][j - 1] * (m - 1) : 0)) % MOD;
    printf("%lld", f[n][k]);
}