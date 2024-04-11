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

int n, m, k, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, size[55][55], sum;
bool vis[55][55];
char g[55][55];

void dfs(int x, int y)
{
    size[x][y] = 1;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
        if (g[x + dx[i]][y + dy[i]] == '.' && !vis[x + dx[i]][y + dy[i]])
        {
            dfs(x + dx[i], y + dy[i]);
            size[x][y] += size[x + dx[i]][y + dy[i]];
        }
}
void dfs2(int x, int y, char c)
{
    g[x][y] = c;
    for (int i = 0; i < 4; i++)
        if (g[x + dx[i]][y + dy[i]] == '.')
            dfs2(x + dx[i], y + dy[i], c);
}

signed main()
{
    fast;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    for (int i = 1; i <= n; i++)
    {
        if (g[i][1] == '.' && !vis[i][1])
            dfs(i, 1);
        if (g[i][m] == '.' && !vis[i][m])
            dfs(i, m);
    }
    for (int i = 1; i <= m; i++)
    {
        if (g[1][i] == '.' && !vis[1][i])
            dfs(1, i);
        if (g[n][i] == '.' && !vis[n][i])
            dfs(n, i);
    }
    vector<pair<int, pii>> v;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (g[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j);
                v.pb((make_pair(size[i][j], make_pair(i, j))));
            }
    sort(v.begin(), v.end(), greater<pair<int, pii>>());
    while (v.size() > k)
    {
        dfs2(v.back().S.F, v.back().S.S, '*');
        sum += v.back().F;
        v.pop_back();
    }
    cout << sum << '\n';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << g[i][j];
        cout << '\n';
    }
}