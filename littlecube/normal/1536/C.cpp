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

ll N, ans[500005], pre[500005][2];
map<pii, int> mp;
void solve()
{
    mp.clear();
    cin >> N;
    for (int i = 1; i <= N; i++)
        pre[i][0] = pre[i][1] = 0, ans[i] = 1;
    for (int i = 1; i <= N; i++)
    {
        char c;
        cin >> c;
        pre[i][0] = pre[i - 1][0];
        pre[i][1] = pre[i - 1][1];
        pre[i][c == 'D' ? 0 : 1]++;
    }
    for (int i = 1; i <= N; i++)
    {
        int a = pre[i][0], b = pre[i][1], gcd = __gcd(a, b);
        a /= gcd;
        b /= gcd;
        mp[{a, b}]++;
        cout << mp[{a, b}] << " \n"[i == N];
    }
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}