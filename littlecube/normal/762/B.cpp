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

int a, b, c, M;
pll p[300005];
ll cnt, cost;

signed main()
{
    fast;
    cin >> a >> b >> c >> M;
    for (int i = 1; i <= M; i++)
    {
        string s;
        cin >> p[i].F >> s;
        p[i].S = (s[0] == 'U' ? 0 : 1);
    }
    sort(p + 1, p + 1 + M);
    for (int i = 1; i <= M; i++)
    {
        if (p[i].S == 0)
        {
            if (a)
            {
                a--;
                cnt++, cost += p[i].F;
            }
            else if (c)
            {
                c--;
                cnt++, cost += p[i].F;
            }
        }
        else
        {
            if (b)
            {
                b--;
                cnt++, cost += p[i].F;
            }
            else if (c)
            {
                c--;
                cnt++, cost += p[i].F;
            }
        }
    }
    cout << cnt << " " << cost << '\n';
}