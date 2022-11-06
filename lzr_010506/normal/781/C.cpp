#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 1000100;

int n, m, K;
vector<int> adj[maxn + 5];

int dfs_tot = 0;
int seq[maxn + 5];

bool vis[maxn + 5];

void dfs(int x)
{
	seq[dfs_tot++] = x;
	vis[x] = 1;
	for (auto y : adj[x]) if (!vis[y])
	{
		dfs(y);
		seq[dfs_tot++] = x;
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &K);
	for(int i = 0; i < m; i ++)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(vis, 0, sizeof vis);
	dfs_tot = 0;
	dfs(0);
	int now = 0;
	for(int i = 0; i < K; i ++)
	{
		int num = (dfs_tot - now) / (K - i);
		printf("%d", num);
		for(int j = 0; j < num; j ++) printf(" %d", seq[now++] + 1);
		printf("\n");
	}
	return 0;
}