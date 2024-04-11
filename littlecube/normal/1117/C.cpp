/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
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
using namespace __gnu_pbds;

int N, x[100005], y[100005];
pii s, e;

signed main()
{
    fast;
    cin >> s.F >> s.S >> e.F >> e.S;
    e.F -= s.F;
    e.S -= s.S;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        char c;
        cin >> c;
        x[i] = x[i - 1];
        y[i] = y[i - 1];
        if (c == 'U')
            y[i]++;
        else if (c == 'D')
            y[i]--;
        else if (c == 'L')
            x[i]--;
        else
            x[i]++;
    }
    ll L = 0, R = 3e18;
    while (L < R)
    {
        ll mid = (L + R) / 2;
        pii wind = {x[N] * (mid / N) + x[mid % N],
                    y[N] * (mid / N) + y[mid % N]};
        if(abs(wind.F - e.F) + abs(wind.S - e.S) <= mid)
            R = mid;
        else
            L = mid + 1;
    }
    cout << (L >= 3e18 ? -1 : L) << '\n';
}