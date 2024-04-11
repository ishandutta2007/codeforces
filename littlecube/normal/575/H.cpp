/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

const ll mod = 1e9 + 7;
ll fastpow(ll k, int p)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * k % mod;
        p >>= 1;
        k = k * k % mod;
    }
    return a;
}

ll n, fact[2000006], ans;

ll C(int n, int m)
{
    return ((fact[n] * fastpow(fact[m], mod - 2) % mod) * fastpow(fact[n - m], mod - 2) % mod);
}

signed main()
{
    fast;
    cin >> n;
    fact[0] = 1;
    for (int i = 1; i <= 2 * n + 1; i++)
        fact[i] = fact[i - 1] * i % mod;
    for (int i = 1; i <= n + 1; i++)
        ans = (ans + C(i + n, i)) % mod;
    cout << ans << '\n';
}