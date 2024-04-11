#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MN 901000

int h[MN], nxt[2 * MN], to[2 * MN], K = 1;
int id[MN], tot = 0, id2[MN];
int u[MN], v[MN], M = 0;
int low[MN], dfn[MN], D = 0, st[MN], top = 0;
int fa[MN][20], dep[MN], dfnn[MN];
int d[MN], x[MN];
int n, m, q; 

bool cmp(int a, int b) {return dfnn[a] < dfnn[b];}

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void tarjan(int x, int fa)
{
	dfn[x] = low[x] = ++D; st[++top] = x;
	for(int i = h[x]; i; i = nxt[i])
	{
		if((i ^ 1) == fa) continue;
		if(!dfn[to[i]])
		{
			tarjan(to[i], i);
			low[x] = std::min(low[x], low[to[i]]);
		}
		else low[x] = std::min(low[x], dfn[to[i]]);
	}
	if(low[x] == dfn[x])
	{
		++tot;
		do {
			id[st[top]] = tot;
		} while(st[top--] != x);
	}
}

int lca(int u, int v)
{
	if(dep[u] < dep[v]) std::swap(u, v);
	int k = dep[u] - dep[v];
	for(int i = 18; i >= 0; i--) if((k >> i) & 1) u = fa[u][i];
	if(u == v) return u;
	for(int i = 18; i >= 0; i--)
	{
		if(fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	}
	return fa[u][0];
}

void dfs(int x, int f)
{
	dfnn[x] = ++D;
	fa[x][0] = f; dep[x] = dep[f] + 1;
	for(int i = 1; i <= 18; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for(int i = h[x]; i; i = nxt[i]) 
		if(to[i] != f) dfs(to[i], x);
}

int build(int n)
{
	top = 0; st[++top] = d[1];
	int tt = 0;
	for(int i = 2; i <= n; i++)
	{
		int l = lca(d[i], st[top]);
		if(!l)
		{
			while(top > 1) ++M, u[M] = st[top], v[M] = st[top - 1], top--;
			st[top] = d[i];
			continue;
		}
		while(1)
		{
			if(l == st[top]) {st[++top] = d[i]; break;}
			if(dep[l] > dep[st[top - 1]])
			{
				++M; u[M] = l; v[M] = st[top]; top--;
				st[++top] = l; st[++top] = d[i]; 
				tt++; d[n + tt] = l;
				break;
			}
			++M; u[M] = st[top - 1]; v[M] = st[top]; top--;
		}
	}
	while(top > 1) ++M, u[M] = st[top], v[M] = st[top - 1], top--;
	return tt;
}

int R = 0;
int read()
{
	int x; scanf("%d", &x);
	return (x + R - 1) % n + 1;
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &u[i], &v[i]);
		ins(u[i], v[i]); ins(v[i], u[i]);
	}
	for(int i = 1; i <= n; i++)
		if(!dfn[i]) tarjan(i, 0);
	memset(h, 0, sizeof(h)); K = 0; D = 0;
	for(int i = 1; i <= m; i++)
		if(id[u[i]] != id[v[i]]) 
			ins(id[u[i]], id[v[i]]), ins(id[v[i]], id[u[i]]);
	for(int i = 1; i <= n; i++)
		if(!dfnn[i]) dfs(i, 0);
	memcpy(id2, id, sizeof(id));
	memset(h, 0, sizeof(h)); K = 1; 
	memset(dfn, 0, sizeof(dfn));
	for(int i = 1; i <= q; i++)
	{
		int n, m; scanf("%d%d", &n, &m);
		int N = 0;
		for(int j = 1; j <= n; j++) x[j] = id2[read()], d[++N] = x[j];
		M = m;
		for(int j = 1; j <= m; j++) u[j] = id2[read()], v[j] = id2[read()], d[++N] = u[j], d[++N] = v[j];
		std::sort(d + 1, d + N + 1, cmp);
		N = std::unique(d + 1, d + N + 1) - d - 1;;
		N += build(N);
		for(int j = 1; j <= M; j++) ins(u[j], v[j]), ins(v[j], u[j]);
		D = 0; tot = 0; top = 0;
		for(int j = 1; j <= N; j++)
			if(!dfn[d[j]]) tarjan(d[j], 0);
		bool ok = 1;
		for(int j = 1; j <= n; j++) if(id[x[j]] != id[x[1]]) ok = 0;
		if(!ok) puts("NO");
		else puts("YES"), R = (R + i) % ::n;
		for(int j = 1; j <= N; j++) dfn[d[j]] = h[d[j]] = 0; K = 1;
	}
}