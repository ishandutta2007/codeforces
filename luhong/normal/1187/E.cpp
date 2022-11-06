#include <cstdio>
#include <iostream>
#define MN 201000
 
typedef long long ll;
ll f[MN], g[MN];
int h[MN], nxt[2 * MN], to[2 * MN], K = 0; 
int siz[MN];
int fa[MN], n;
int b[MN], o = 0;
 
void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;} 
 
void dfs(int x, int fa)
{
	siz[x] = 1;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		dfs(to[i], x);
		f[x] += f[to[i]]; 
		siz[x] += siz[to[i]];
	}
	f[x] += siz[x];
	o = 0;
	for(int i = h[x]; i; i = nxt[i]) if(to[i] != fa) b[++o] = to[i];
	ll s = 0;
	for(int i = 1; i <= o; i++)
	{
		g[b[i]] = n - siz[b[i]];
		g[b[i]] += s;
		s += f[b[i]];
	}
	s = 0;
	for(int i = o; i >= 1; i--)
	{
		g[b[i]] += s;
		s += f[b[i]];
	}
}
 
void dfs2(int x, int fa)
{
	g[x] += g[fa]; ::fa[x] = fa;
	for(int i = h[x]; i; i = nxt[i]) if(to[i] != fa) dfs2(to[i], x);
}
 
int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v); ins(v, u);
	}
	dfs(1, 0); dfs2(1, 0);
	ll ans = 0;
	for(int i = 1; i <= n; i++) 
	{
		ll s = 0;
		for(int j = h[i]; j; j = nxt[j])
			if(to[j] != fa[i]) s += f[to[j]];
		s += g[i]; 
		ans = std::max(ans, s + (i == 1 ? 0 : n));
	}
	printf("%lld\n", ans);
}