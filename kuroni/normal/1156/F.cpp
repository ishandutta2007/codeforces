#include <iostream>
#include <cstdio>
using namespace std;

const int N = 5005, MOD = 998244353;

int n, u, a[N], su[N];
long long wi = 0, to = 0, inv[N], f[N][N], g[N][N];

long long pw(int u, int p)
{
    long long ret = 1;
    for (int i = 31 - __builtin_clz(p); i >= 0; i--)
    {
        (ret *= ret) %= MOD;
        if (p >> i & 1)
            (ret *= u) %= MOD;
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &u);
        a[u]++;
    }
    for (int i = 1; i <= n; i++)
    {
        su[i] = su[i - 1] + a[i];
        g[i - 1][0] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = g[i - 1][j - 1] * a[i] % MOD * inv[n + 1 - j] % MOD;
            (to += f[i][j] * (su[i - 1] - (j - 1)) % MOD * inv[n - j]) %= MOD;
            (wi += f[i][j] * (a[i] - 1) % MOD * inv[n - j]) %= MOD;
            (to += f[i][j] * (a[i] - 1) % MOD * inv[n - j]) %= MOD;
            g[i][j] = (g[i - 1][j] + f[i][j]) % MOD;
        }
    printf("%lld\n", wi * pw(to, MOD - 2) % MOD);
}