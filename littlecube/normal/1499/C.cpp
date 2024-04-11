#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

void solve()
{
    ll n, m, k, ansl, ansr, minl = 0, minr = 0, l, r, res = 1000000000000000;
    vector<ll> a;
    cin >> n;
    m = k = n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ansl = a[0] * k;
    ansr = a[1] * m;
    l = a[0], r = a[1];
    minl = a[0];
    minr = a[1];
    k--, m--;
    res = ansl + ansr;
    for (int i = 2; i < n; i++)
    {
        if (i % 2 == 0)
        {
            k--;
            l += a[i];
            minl = min(a[i], minl);
            ansl = l + minl * k;
        }
        else
        {
            m--;
            r += a[i];
            minr = min(a[i], minr);
            ansr = r + minr * m;
        }
        res = min(ansl + ansr, res);
    }
    cout << res << '\n';
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}