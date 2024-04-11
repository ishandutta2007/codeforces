#include <iostream>
#include <cstdio>
#define MN 200100

int n, m; 
int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
int id[20][MN], LCA[20][MN], b[MN], f[MN], dep[MN];
int Max[20][MN], Min[20][MN];
int dfn[MN], tt = 0, tot = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void dfs(int x, int fa, int d)
{
	id[0][++tot] = Max[0][x] = Min[0][x] = LCA[0][x] = x; 
	f[x] = tot; dep[x] = d; dfn[x] = ++tt;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		dfs(to[i], x, d + 1);
		id[0][++tot] = x;
	}
}

int lca(int x, int y)
{
	x = f[x], y = f[y];
	if(x > y) std::swap(x, y);
	int len = y - x + 1;
	int u = id[b[len]][x], v = id[b[len]][y - (1 << b[len]) + 1];
	if(dep[u] < dep[v]) return u;
	else return v;
}

void init()
{
	for(int i = 1; i <= 19; i++)
		for(int j = 1; j + (1 << i) - 1 <= tot; j++)
		{
			int u = id[i - 1][j], v = id[i - 1][j + (1 << (i - 1))];
			if(dep[u] < dep[v]) id[i][j] = u;
			else id[i][j] = v;
		}
	for(int i = 1; i <= 19; i++)
		for(int j = 1; j + (1 << i) - 1 <= n; j++)
		{
			int u = Max[i - 1][j], v = Max[i - 1][j + (1 << (i - 1))];
			if(dfn[u] < dfn[v]) Max[i][j] = v;
			else Max[i][j] = u;
			
			u = Min[i - 1][j], v = Min[i - 1][j + (1 << (i - 1))];
			if(dfn[u] < dfn[v]) Min[i][j] = u;
			else Min[i][j] = v;
			
			LCA[i][j] = lca(LCA[i - 1][j], LCA[i - 1][j + (1 << (i - 1))]);
		}
}

int solve(int l, int r)
{
	int len = r - l + 1;
	return lca(LCA[b[len]][l], LCA[b[len]][r - (1 << b[len]) + 1]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 2; i <= n; i++)
	{
		int fa; scanf("%d", &fa);
		ins(fa, i);
	}
	b[0] = -1; for(int i = 1; i <= 2 * n; i++) b[i] = b[i >> 1] + 1;
	dfs(1, 0, 0); init();
	for(int i = 1; i <= m; i++)
	{
		int l, r; scanf("%d%d", &l, &r);
		int len = r - l + 1;
		int u = Max[b[len]][l], v = Max[b[len]][r - (1 << b[len]) + 1];
		int o1, o2;
		if(dfn[u] < dfn[v]) o1 = v;
		else o1 = u;
		int lca1, lca2; 
		if(o1 == l) lca1 = solve(l + 1, r);
		else if(o1 == r) lca1 = solve(l, r - 1);
		else lca1 = lca(solve(l, o1 - 1), solve(o1 + 1, r));
		
		u = Min[b[len]][l], v = Min[b[len]][r - (1 << b[len]) + 1];
		if(dfn[u] < dfn[v]) o2 = u;
		else o2 = v;
		if(o2 == l) lca2 = solve(l + 1, r);
		else if(o2 == r) lca2 = solve(l, r - 1);
		else lca2 = lca(solve(l, o2 - 1), solve(o2 + 1, r));
		if(dep[lca1] < dep[lca2]) printf("%d %d\n", o2, dep[lca2]);
		else printf("%d %d\n", o1, dep[lca1]);
	}
	return 0;
}