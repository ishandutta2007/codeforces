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

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;
        if ((2 * n - k1 - k2) / 2 >= b && (k1 + k2) / 2 >= w)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}