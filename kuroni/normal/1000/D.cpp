#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1005, MOD = 998244353;

int n, a[N];
long long ans = 0, fct[N], inv[N], f[N];

long long pw(long long u, int p)
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

long long C(int n, int k)
{
    return fct[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main()
{
    scanf("%d", &n);
    fct[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        f[i] = 1;
        fct[i] = fct[i - 1] * i % MOD;
        inv[i] = pw(fct[i], MOD - 2);
    }
    for (int i = 1; i <= n; i++)
        if (a[i] > 0)
        {
            for (int j = i + a[i] + 1; j <= n; j++)
                (f[j] += f[i] * C(j - i - 1, a[i])) %= MOD;
            if (i + a[i] <= n)
                (ans += f[i] * C(n - i, a[i])) %= MOD;
        }
    printf("%lld", ans);
}