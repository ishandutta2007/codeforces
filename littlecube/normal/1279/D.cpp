#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, x = 0, y = 1, k[1000005], arr[1000005];
vector<pii> v;
ll inv(ll i)
{
    if (i == 1)
        return 1;
    return (MOD2 - (MOD2 / i)) * inv(MOD2 % i) % MOD2;
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        y = (y + k[i]) % MOD2;
        for (int j = 1; j <= k[i]; j++)
        {
            int a;
            cin >> a;
            v.emplace_back(make_pair(i, a));
            arr[a]++;
        }
    }
    for (auto i : v)
    {
        x = (arr[i.second] * y + (n * (n * k[i.first] % MOD2) % MOD2) * x) % MOD2;
        y = y * (n * (n * k[i.first] % MOD2) % MOD2) % MOD2;
    }
    cout << x * inv(y) % MOD2 << '\n';
}