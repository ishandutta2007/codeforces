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

ll t, n, s, arr[200005], opt[2];

signed main()
{
    fast;
    cin >> t;
    while (t--)
    {
        opt[0] = opt[1] = 0;
        cin >> n >> s;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        int ldx = 1, rdx = 1;
        ll cur = s;
        while (ldx <= n && rdx <= n)
        {
            if (cur + arr[rdx] < 0)
            {
                cur -= arr[ldx];
                ldx++;
            }
            else
            {
                cur += arr[rdx];
                rdx++;
            }
            if (rdx - ldx > opt[1] - opt[0])
                opt[0] = ldx, opt[1] = rdx - 1;
        }
        if (opt[0] == 0)
            cout << -1 << '\n';
        else
            cout << opt[0] << " " << opt[1] << '\n';
    }
}