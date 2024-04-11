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

int m, n[100005], arr[200005], vis[200005], ptr[300005], deg[300005], idx;
vector<pii> sol;
vector<pii> E[300005];
map<int, int> lisan;

void dfs(int k)
{
    for (; ptr[k] < E[k].size(); ptr[k]++)
        if (!vis[E[k][ptr[k]].S])
        {
            int v = E[k][ptr[k]].F, id = E[k][ptr[k]].S;
            vis[id] = 1;
            dfs(v);
            sol.emplace_back(pii{id, v > m});
        }
}

signed main()
{
    fast;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> n[i];
        n[i] += n[i - 1];
        for (int j = n[i - 1] + 1; j <= n[i]; j++)
        {
            cin >> arr[j];
            if (lisan[arr[j]] == 0)
                lisan[arr[j]] = ++idx;
            arr[j] = lisan[arr[j]];
            E[i].emplace_back(pii{arr[j] + m, j});
            E[arr[j] + m].emplace_back(pii{i, j});
            deg[arr[j]]++;
        }
    }
    for (int i = 1; i <= 300000; i++)
        if (deg[i] & 1)
        {
            cout << "NO\n";
            return 0;
        }
    for (int i = 1; i <= m; i++)
        if (ptr[i] < E[i].size())
            dfs(i);
    reverse(sol.begin(), sol.end());
    for (auto [e, ans] : sol)
        arr[e] = ans;
    cout << "YES\n";
    for (int i = 1; i <= m; i++)
    {
        for (int j = n[i - 1] + 1; j <= n[i]; j++)
            cout << (arr[j] ? 'R' : 'L');
        cout << '\n';
    }
}