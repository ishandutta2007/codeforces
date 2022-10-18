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

int n, m, ori[200005], x[2000005], vis[200005], deg[200005], ans[200005];
bool valid = 1;
vector<pii> E[200005];
vector<int> nE[200005], topo;

void dfs(int k)
{
    for (auto [i, _] : E[k])
        if (!ori[i])
        {
            ori[i] = ori[k] ^ 3;
            dfs(i);
        }
        else if ((ori[i] ^ ori[k]) != 3)
            valid = 0;
}

// Pretest: 12
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        E[x].emplace_back(pii{y, t});
        E[y].emplace_back(pii{x, t});
    }
    for (int i = 1; i <= n; i++)
        if (!ori[i])
        {
            ori[i] = 1;
            dfs(i);
        }
    if (!valid)
        cout << "NO\n";
    else
    {
        for (int i = 1; i <= n; i++)
            for (auto [j, t] : E[i])
                if (ori[i] == 2 && t == 2)
                {
                    nE[i].emplace_back(j);
                    deg[j]++;
                }
                else if (ori[i] == 1 && t == 1)
                {
                    nE[i].emplace_back(j);
                    deg[j]++;
                }
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (deg[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            topo.emplace_back(q.front());
            for (int i : nE[q.front()])
            {
                deg[i]--;
                if (deg[i] == 0)
                    q.push(i);
            }
            q.pop();
        }
        if (topo.size() != n)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                ans[topo[i]] = i;
            for (int i = 1; i <= n; i++)
                cout << (ori[i] == 1 ? "L " : "R ") << ans[i] << '\n';
        }
    }
}

signed main()
{
    solve();
}