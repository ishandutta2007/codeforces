#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

//map<tuple<ll, ll, ll>, ll> mp;

ll n, l, r;

ll getsize(ll n)
{
    return (1LL << ((ll)log2(n) + 1)) - 1;
}

ll solve(ll n, ll l, ll r)
{
    if (l == 1 && r == getsize(n))
        return n;

    ll res = 0;

    //if (mp[make_tuple(n, l, r)] != 0 && n < (1 << 2))
    //    return mp[make_tuple(n, l, r)];

    if (l <= getsize(n) / 2)
        res += solve(n / 2, l, min(getsize(n) / 2, r));
    if (n % 2 == 1 && l <= getsize(n) / 2 + 1 && r >= getsize(n) / 2 + 1)
        res++;
    if (r > 1 + getsize(n) / 2)
        res += solve(n / 2, max(1LL, l - 1 - getsize(n) / 2), r - 1 - getsize(n) / 2);
    //mp[make_tuple(n, l, r)] = res;
    return res;
}

signed main()
{
    cin >> n >> l >> r;
    cout << solve(n, l, r);
}