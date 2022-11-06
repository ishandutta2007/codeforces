#include <cstdio>
#include <iostream>
#define MN 301000

typedef long long ll;

int h[MN], nxt[2 * MN], to[2 * MN], cost[2 * MN], K = 0;
int fa[21][MN], dep[MN];
ll f[MN], g[MN], s[MN], v[MN];
int c[MN], a[MN];
int b[MN], o = 0;

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cost[K] = c;}

void dfs1(int x, int fa)
{
	::fa[0][x] = fa;
	dep[x] = dep[fa] + 1;
	
	for(int i = 1; i <= 19; i++) ::fa[i][x] = ::fa[i - 1][::fa[i - 1][x]];

	f[x] = a[x] - 2 * c[x];
	
	for(int i = h[x]; i; i = nxt[i])
		if(to[i] != fa) c[to[i]] = cost[i], dfs1(to[i], x);
		
	o = 0;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		f[x] += std::max(f[to[i]], 0ll);
		v[x] += std::max(f[to[i]], 0ll);
		b[++o] = to[i];
	}
	
	f[x] = std::max(f[x], 0ll);
	
	ll S = 0;
	for(int i = 1; i <= o; i++)
	{
		g[b[i]] += S;  
		S += std::max(f[b[i]], 0ll);
	}
	
	S = 0;
	for(int i = o; i >= 1; i--)
	{
		g[b[i]] += S;  
		S += std::max(f[b[i]], 0ll);
	}
}

void dfs2(int x)
{
	g[x] = std::max(g[x] + g[fa[0][x]] - 2 * c[x] + a[fa[0][x]], 0ll);
	s[x] = s[fa[0][x]] + v[x] - f[x] + a[x] - c[x];
	
	for(int i = h[x]; i; i = nxt[i]) 
		if(to[i] != fa[0][x]) dfs2(to[i]);
}

int lca(int u, int v)
{
	for(int i = 19; i >= 0; i--)
	{
		if(dep[fa[i][u]] >= dep[v]) u = fa[i][u];
		if(dep[fa[i][v]] >= dep[u]) v = fa[i][v];
	}
	if(u == v) return v;
	for(int i = 19; i >= 0; i--)
	{
		if(fa[i][u] != fa[i][v])
			u = fa[i][u], v = fa[i][v];
	}
	return fa[0][u];
}

int main()
{
	int n, q; scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i < n; i++)
	{
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		ins(u, v, c); ins(v, u, c);
	}
	dfs1(1, 0);
	dfs2(1);
	for(int i = 1; i <= q; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		int l = lca(u, v);
		printf("%lld\n", s[u] + s[v] - 2 * s[l] + ::v[l] + g[l] + a[l]);
	}
}