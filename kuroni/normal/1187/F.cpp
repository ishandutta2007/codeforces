#include <bits/stdc++.h>
using namespace std;

const int N = 200005, MOD = 1E9 + 7;

int n, l[N], r[N];
long long cur, pr[N], su[N];

long long pw(int u, int p)
{
    long long ret = 1;
    if (p == 0)
        return ret;
    for (int i = 31 - __builtin_clz(p); i >= 0; i--)
    {
        (ret *= ret) %= MOD;
        if (p >> i & 1)
            (ret *= u) %= MOD;
    }
    return ret;
}

long long prob(int l1, int r1, int l2, int r2)
{
    int cur = max(0, min(r1, r2) - max(l1, l2) + 1);
    int x = r1 - l1 + 1, y = r2 - l2 + 1;
    return (1 - cur * pw(1LL * x * y % MOD, MOD - 2)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i];
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    pr[1] = 1;
    for (int i = 2; i <= n; i++)
        pr[i] = (prob(l[i - 1], r[i - 1], l[i], r[i]) + MOD) % MOD;
    for (int i = n; i >= 1; i--)
        su[i] = (su[i + 1] + pr[i]) % MOD;
    long long ans = su[2];
    for (int i = 2; i < n; i++)
    {
        (ans += pr[i] * su[i + 2]) %= MOD;
        int tl = l[i], tr = r[i];
        long long wtf = 0;
        if (tl <= tr && tl < l[i + 1])
        {
            int xl = tl, xr = min(tr, l[i + 1] - 1);
            cur = prob(l[i - 1], r[i - 1], xl, xr);
            (cur *= prob(xl, xr, l[i + 1], r[i + 1])) %= MOD;
            (wtf += cur * (xr - xl + 1)) %= MOD;
            tl = xr + 1;
        }
        if (tl <= tr && tl <= r[i + 1])
        {
            int xl = tl, xr = min(tr, r[i + 1]);
            cur = prob(l[i - 1], r[i - 1], xl, xr);
            (cur *= prob(xl, xr, l[i + 1], r[i + 1])) %= MOD;
            (wtf += cur * (xr - xl + 1)) %= MOD;
            tl = xr + 1;
        }
        if (tl <= tr)
        {
            cur = prob(l[i - 1], r[i - 1], tl, tr);
            (cur *= prob(tl, tr, l[i + 1], r[i + 1])) %= MOD;
            (wtf += cur * (tr - tl + 1)) %= MOD;
        }
        (ans += wtf * pw(r[i] - l[i] + 1, MOD - 2)) %= MOD;
    }
    cout << ((ans * 2 + su[1]) % MOD + MOD) % MOD;
}