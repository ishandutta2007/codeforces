#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 10;
int deg[N], ans[N], col[N], ce[N];
vector<int> G[N];
void dfs(int x, int fa)
{
	ce[x] = ce[fa] + 1;
	for(auto to : G[x])
	{
		if(to == fa) continue;
		dfs(to, x);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T --)
	{
		int n;
		cin >> n;
		rep(i, 1, n) G[i].clear(), deg[i] = 0;
		rep(i, 1, n - 1)
		{
			int u, v;
			cin >> u >> v;
			G[u].pb(v);
			G[v].pb(u);
			deg[u] ++;
			deg[v] ++;
		}
		dfs(1, 0);
		rep(i, 1, n)
			if(ce[i] & 1) printf("%d ", deg[i]);
			else printf("%d ", -deg[i]);
		puts("");

	}


	return 0;
}