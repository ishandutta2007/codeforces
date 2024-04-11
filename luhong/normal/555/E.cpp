#include <cstdio>
#include <cstring> 
#include <iostream>
#define MN 201000

int n, m, q;
bool vis[MN];
int h[MN], nxt[2 * MN], to[2 * MN], K = 1;
int dep[MN], st[MN][20];
int s1[MN], s2[MN], dfn[MN], low[MN], tot = 0;
bool flag = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;} 

void dfs(int x, int f)
{
	vis[x] = 1; st[x][0] = f; dep[x] = dep[f] + 1;
	for(int i = 1; i <= 19; i++) st[x][i] = st[st[x][i - 1]][i - 1];
	for(int i = h[x]; i; i = nxt[i])
		if(!vis[to[i]])	dfs(to[i], x);
}

void dfs2(int x, int f)
{
	vis[x] = 1; dfn[x] = low[x] = ++tot;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(i == (f ^ 1)) continue;
		if(!vis[to[i]])
		{
			dfs2(to[i], i);
			s1[x] += s1[to[i]];
			s2[x] += s2[to[i]];
			low[x] = std::min(low[x], low[to[i]]);
		}
		else low[x] = std::min(low[x], dfn[to[i]]);
	}
	if(f && low[x] == dfn[x])
		if(s1[x] && s2[x]) flag = 1;
}

int lca(int u, int v)
{
	for(int i = 19; i >= 0; i--)
	{
		if(dep[st[u][i]] >= dep[v]) u = st[u][i]; 
		if(dep[st[v][i]] >= dep[u]) v = st[v][i];
	}
	if(u == v) return u;
	for(int i = 19; i >= 0; i--)
		if(st[u][i] != st[v][i])
		{
			u = st[u][i];
			v = st[v][i];
		}
	return st[u][0];
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= m; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v); ins(v, u);
	}
	for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i, 0);
	for(int i = 1; i <= q; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		int l = lca(u, v);
		if(l == 0) return 0 * puts("No");
		s1[u]++; s1[l]--;
		s2[v]++; s2[l]--;
	}
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++)
		if(!vis[i])	dfs2(i, 0);
	if(!flag) puts("Yes");
	else puts("No");
}