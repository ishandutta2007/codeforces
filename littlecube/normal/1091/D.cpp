#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll fac[1000000];

ll cfac(ll n)
{
    if (fac[n] == 0)
        fac[n] = cfac(n - 1) * n % MOD2;
    return fac[n];
}

int main()
{
    fac[0] = 1;
    fac[1] = 1;
    //fast;
    ll n, r = 0;
    cin >> n;
    for (ll i = 2; i < n; i++)
    {
        r = (i + 1) * (cfac(i) - 1 + r);
        r %= MOD2;
    }
    r += cfac(n);
    r %= MOD2;
    cout << r;
    return 0;
}