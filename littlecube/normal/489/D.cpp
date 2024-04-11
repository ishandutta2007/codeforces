/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
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

int n, m, cnt, x, y;
vector<int> e[3005];
signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        e[x].pb(y);
    }
    for (int i = 1; i <= n; i++)
    {
        int tmp[3005] = {0};
        for (int j : e[i])
            for (int k : e[j])
                tmp[k]++;
        for (int j = 1; j <= n; j++)
            cnt += tmp[j] * (tmp[j] - 1) / 2;
        cnt -= tmp[i] * (tmp[i] - 1) / 2;
    }
    cout << cnt << '\n';
}