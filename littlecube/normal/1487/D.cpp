#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    vector<ll> v;
    for (ll i = 3; i < 1000000; i += 2)
        v.emplace_back((i * i) / 2);
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << (upper_bound(v.begin(), v.end(), n - 1) - v.begin()) << '\n';
    }
}