#include <cstdio>
#include <iostream>
#define MN 301000

long long dp[MN], f[MN], g[MN], ans = 0;
int h[MN], nxt[2 * MN], to[2 * MN], cost[2 * MN], K = 0;
int w[MN];

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cost[K] = c;} 
void dfs(int x, int fa)
{
	f[x] = g[x] = dp[x] = w[x];
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		dfs(to[i], x);
		dp[x] = std::max(dp[x], g[x] - cost[i] + g[to[i]]);
		g[x] = std::max(g[x], f[x] - cost[i] + g[to[i]]); 
	}
	ans = std::max(ans, g[x]);
	ans = std::max(ans, f[x]);
	ans = std::max(ans, dp[x]);
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for(int i = 1; i < n; i++)
	{
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		ins(u, v, c); ins(v, u, c);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}