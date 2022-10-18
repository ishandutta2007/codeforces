/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll n, m, k, a;

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        ll N = 0, all2N = 1, M = 0, all2M = 1;
        vector<int> v(k);
        for (auto &a : v)
            cin >> a;
        sort(v.begin(), v.end(), greater<>());
        for (auto &a : v)
        {
            if (a / m >= 2)
            {
                N += a / m;
                if(a / m != 2)
                    all2N = 0;
            }
            if (a / n >= 2)
            {
                M += a / n;
                if(a / n != 2)
                    all2M = 0;
            }
        }
        if ((N > n && ((N - n) % 2 == 0 || !all2N)) || (N == n) || (M > m && ((M - m) % 2 == 0 || !all2M)) || (M == m))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}