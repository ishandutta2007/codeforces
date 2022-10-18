/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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

int n, k, a[200005], p[200005];

signed main()
{
    fast;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int L = 1, R = n;
    while (L < R)
    {
        int mid = (L + R + 1) / 2;
        for (int i = 1; i <= n; i++)
            p[i] = (a[i] >= mid) * 2;
        for (int i = 1; i <= n; i++)
            p[i] += p[i - 1];
        for (int i = 1; i <= n; i++)
            p[i] -= i;
        int mi = n;
        bool valid = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i - k >= 0)
                mi = min(mi, p[i - k]);
            if(p[i] > mi)
                valid = 1;
        }
        if(valid)
            L = mid;
        else
            R = mid - 1;
    }
    cout << L << '\n';
}