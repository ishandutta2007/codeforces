#include <iostream>
#include <cstdio>
using namespace std;

const int N = 200005, MOD = 998244353, INV = 499122177;

int n, a[N], bit[N], sum[N];
bool chk[N];
long long ans = 0, le = 0, ri = 0, fct[N], inv[N];

long long pw(long long u, int v)
{
    long long ret = 1;
    for (int i = 31 - __builtin_clz(v); i >= 0; i--)
    {
        (ret *= ret) %= MOD;
        if (v >> i & 1)
            (ret *= u) %= MOD;
    }
    return ret;
}

void init()
{
    fct[0] = 1;
    for (int i = 1; i < N; i++)
        fct[i] = fct[i - 1] * i % MOD;
    inv[N - 1] = pw(fct[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

void upd(int u)
{
    for (; u > 0; u -= u & -u)
        bit[u]++;
}

int que(int u)
{
    int ret = 0;
    for (; u <= n; u += u & -u)
        ret += bit[u];
    return ret;
}

int main()
{
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        if (a[i] != -1)
        {
            (ans += que(a[i])) %= MOD;
            chk[a[i]] = true;
            upd(a[i]);
        }
    }
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + (!chk[i]);
    (ans += 1LL * sum[n] * (sum[n] - 1) / 2 % MOD * INV % MOD) %= MOD;
    for (int i = 1; i <= n; i++)
        if (a[i] != -1)
            (le += sum[a[i]]) %= MOD;
        else
            (ans += fct[sum[n] - 1] * le % MOD * inv[sum[n]] % MOD) %= MOD;
    for (int i = n; i >= 1; i--)
        if (a[i] != -1)
            (ri += sum[n] - sum[a[i]]) %= MOD;
        else
            (ans += fct[sum[n] - 1] * ri % MOD * inv[sum[n]] % MOD) %= MOD;
    printf("%lld", ans);
}