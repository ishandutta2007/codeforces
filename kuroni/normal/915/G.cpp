#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 2E6 + 5, MOD = 1E9 + 7;

int n, k, f[MAX], g[MAX], ans = 0;

int pw(int a, int b)
{
    if (b == 1)
        return a;
    long long ret = pw(a, b >> 1);
    (ret *= ret) %= MOD;
    if (b & 1)
        (ret *= a) %= MOD;
    return ret;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
    {
        (g[i] += (pw(i, n) - pw(i - 1, n)) % MOD) %= MOD;
        for (int j = 2 * i; j <= k; j += i)
            (g[j] -= g[i]) %= MOD;
        (ans += (f[i] = ((f[i - 1] + g[i]) % MOD + MOD) % MOD) ^ i) %= MOD;
    }
    printf("%d", ans);
}