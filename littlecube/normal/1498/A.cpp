#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;



signed main()
{
    fast;
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for (int i = n;;i++)
        {
            int k = i, dig = 0;
            while(k > 0)
                dig += k % 10, k /= 10;
            if(__gcd(i, dig) > 1)
            {
                cout << i << '\n';
                break;
            }
        }
    }
}