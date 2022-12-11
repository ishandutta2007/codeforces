#include <bits/stdc++.h>

using namespace std;

#define debug(...) 42

using ll = long long;

#define lb lower_bound
#define ub upper_bound

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

/*
vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k)
{
    if (k < 0 || k > n)
    {
        return 0;
    }
    while ((int)fact.size() < n + 1)
    {
        fact.push_back(fact.back() * (int)fact.size());
        inv_fact.push_back(1 / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}
*/
// (int)1e9 + 7;

int main()
{
    FAST_IO;
    int n;
    cin >> n;
    int a[n + 1];
    ll sum[n + 1], fsum[n + 1];
    sum[0] = fsum[0] = 0;
    FOR(i, 1, n + 1)
    cin >> a[i];
    int st = 1, en = 1, further = 1;
    ll base = 0;
    int r[n + 1], f[n + 1];
    while (st <= n)
    {
        while (en + 1 <= n && a[en + 1] >= en - st + 2)
            en++;
        further = max(further, min(en + 1, n));
        while (further + 1 <= n && a[further + 1] >= further - st + 2)
            further++;
        f[st] = further;
        fsum[st] = fsum[st - 1] + f[st];
        r[st] = en;
        sum[st] = sum[st - 1] + r[st];
        base += en - st + 1;
        st++;
    }
    debug(base);
    int q;
    cin >> q;
    while (q--)
    {
        int p, x;
        cin >> p >> x;
        ll delta = 0;
        if (a[p] > x)
        {
            int s = 1, e = p;
            while (s < e)
            {
                int m = (s + e) / 2;
                if (r[m] >= p)
                {
                    e = m;
                }
                else
                    s = m + 1;
            }
            ll i = s, j = p - x;
            if (i <= j)
                delta -= (sum[j] - sum[i - 1]) - (j - i + 1) * (p - 1);
        }
        else if (a[p] < x)
        {
            ll i = lb(r + 1, r + n + 1, p - 1) - r, j = ub(r + 1, r + n + 1, p - 1) - r - 1;
            i = max(i, (ll)p - x + 1);
            if (i <= j)
                delta += (fsum[j] - fsum[i - 1]) - (sum[j] - sum[i - 1]);
        }
        cout << base + delta << '\n';
    }
}