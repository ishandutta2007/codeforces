#include <bits/stdc++.h>
using namespace std;
const int maxn = 15000010, mod = 1e9 + 7, iv = (mod + 1) >> 1;
int jc[maxn + 10], injc[maxn + 10], test, n, m, f[11111111], g[11111111], ans, h[11111111];
int binpow(int a, int t)
{
    int res = 1, p = a;
    for (int i = t; i; i >>= 1)
    {
        if (i & 1) res = 1ll * res * p % mod;
        p = 1ll * p * p % mod;
    }
    return res;
}
void Init()
{
    jc[0] = 1;
    for (int i = 1; i <= maxn; i++) jc[i] = 1ll * jc[i - 1] * i % mod;
    injc[maxn] = binpow(jc[maxn], mod - 2);
    for (int i = maxn - 1; i >= 0; i--) injc[i] = 1ll * injc[i + 1] * (i + 1) % mod;
}
int C(int n, int k)
{
    if (n < 0 || k < 0 || n < k) return 0;
    return 1ll * jc[n] * injc[k] % mod * injc[n - k] % mod;
}
int main()
{
    Init();
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 2; i <= n + m + 1; i++)
        {
            f[i] = 1ll * C(i + n - 2, n) * C(i + m - 2, m) % mod;
        }
        if ((n + m) & 1) g[0] = 0;
        else g[0] = 1;
        for (int i = 1; i <= n + m - 2; i++)
        {
            if ((n + m - i) & 1) g[i] = 1ll * iv * ((g[i - 1] - C(n + m - 2, i)) % mod - C(n + m - 2, i - 1)) % mod;
            else g[i] = 1ll * iv * ((g[i - 1] + C(n + m - 2, i)) % mod + C(n + m - 2, i - 1)) % mod;
        }
        g[n + m - 1] = g[n + m] = 0;
        for (int i = 0; i <= n + m; i++)
        {
            if ((n + m - i) & 1) g[i] = (g[i] - C(n + m - 1, i - 1)) % mod;
            else g[i] = (g[i] + C(n + m - 1, i - 1)) % mod;
        }
        if ((n + m) & 1) h[0] = -((n + m + 1) >> 1);
        else h[0] = -((n + m) >> 1) + (n + m + 1);
        for (int i = 1; i <= n + m; i++)
        {
            if ((n + m - i) & 1) h[i] = 1ll * iv * ((-1ll * C(m + n, i) * (n + m + 1) - 1ll * C(m + n, i - 1) * (n + m + 1) + g[i] + h[i - 1]) % mod) % mod;
            else h[i] = 1ll * iv * ((1ll * C(m + n, i) * (n + m + 1) + 1ll * C(m + n, i - 1) * (n + m + 1) + g[i] + h[i - 1]) % mod) % mod;
        }
        ans = 0;
        for (int i = 2; i <= n + m + 1; i++)
        {
            ans = (1ll * f[i] * h[i - 1] + ans) % mod;
        }
        printf("%d\n", (ans + mod) % mod);
    }
    return 0;
}