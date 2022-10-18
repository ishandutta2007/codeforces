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
using namespace __gnu_pbds;

int n, m, arr[11][100005], pos[11][100005], cur[11], vis[100005];
ll ans;

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            pos[i][arr[i][j]] = j;
        }
    arr[1][n + 1] = -1;
    vector<int> order;
    for (int j = 1; j <= n; j++)
        order.emplace_back(arr[1][j]);
    for (int i : order)
        if (!vis[i])
        {
            vector<int> v;
            for (int j = 1; j <= m; j++)
                cur[j] = pos[j][i];
            bool valid = 1;
            while (valid)
            {
                v.emplace_back(arr[1][cur[1]]);
                for (int j = 1; j <= m; j++)
                    ++cur[j];
                for (int j = 2; j <= m; j++)
                    if (arr[j][cur[j]] != arr[1][cur[1]])
                        valid = false;
                if(cur[1] > n)
                    valid = false;
            }
            ans += v.size() * (v.size() + 1) / 2;
            for(int j : v)
                vis[j] = 1;
        }
    cout << ans << '\n';
}