#include <bits/stdc++.h>
#include <unordered_map>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define X first
#define Y second
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define ll long long
using namespace std;
const int N = 200010;
vector<int> G[N];
int dep[N], fa[N], md[N], hson[N];
int top[N], len[N];
int a[N], son[N], deg[N];
ll ans, f[N];
bool cmp(int x, int y)
{
	return f[x] > f[y];
}
void dfs1(int u,int fa)
{
    for(auto v : G[u])
    {
        if(v == fa) continue;
        dfs1(v, u);
        if(f[v] >= f[son[u]]) son[u] = v;
    }
    f[u] = max(f[son[u]], (ll)a[u]);
    if(fa)
    {
        for(auto v : G[u])
        {
            if(v == fa) continue;
            if(v != son[u]) ans += f[v];
        }
    }
    else
    {
        if(deg[u] == 1) ans += 2LL * f[u];
        else
        {
            vector<int> son;
            for(auto v : G[u])son.pb(v);
        	sort(son.begin(), son.end(), cmp);
        	rep(i, 2, son.size() - 1) ans += f[son[i]];
            ans += 2 * f[u];
        }
    }
}
// void dfs2(int u, int tp)
// {
// 	top[u] = tp;
// 	len[u] = md[u] - dep[top[u]] + 1;
// 	if(hson[u]) dfs2(hson[u], tp);
// 	for(auto v : G[u])
// 		if(v != fa[u] && v != hson[u])
// 			dfs2(v, v);
// }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n - 1)
	{
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
		deg[u] ++;
		deg[v] ++;
	}
	int root = 1;
	rep(i, 1, n)
		if(a[i] > a[root]) root = i;
	dfs1(root, 0);
	// dfs2(root, 0);


	cout << ans << "\n";
}