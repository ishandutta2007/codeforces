#include <cstdio>
#include <iostream>
#define MN 101000
#define T 400
#define Max 100000

int h[MN], nxt[2 * MN], to[2 * MN], K = 0; 
int siz[MN], son[MN], top[MN], fa[MN], dfn[MN], rdfn[MN], tt = -1;

int n, m;
bool used[MN];
int a[MN], cnt[MN / T + 5][MN + Max], lazy[MN / T + 5], ans = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void dfs1(int x)
{
	siz[x] = 1;
	for(int i = h[x]; i; i = nxt[i])
	{
		dfs1(to[i]);
		siz[x] += siz[to[i]];
		if(siz[to[i]] > siz[son[x]]) son[x] = to[i];
 	}
}

void dfs2(int x, int tp)
{
	top[x] = tp; dfn[x] = ++tt; rdfn[tt] = x; 
	if(son[x]) dfs2(son[x], tp);
	for(int i = h[x]; i; i = nxt[i])
		if(to[i] != son[x]) dfs2(to[i], to[i]);
}

void init(int x)
{
	int l = x * T, r = std::min(n - 1, (x + 1) * T - 1);
	lazy[x] = Max;
	for(int i = l; i <= r; i++) cnt[x][a[rdfn[i]]]++;
}

void add(int x, int v)
{
	if(v < 0)
	{
		v = -v;
		for(int i = lazy[x]; i < lazy[x] + v; i++) ans += cnt[x][i];
		lazy[x] += v;
	}
	else
	{
		for(int i = lazy[x] - 1; i >= lazy[x] - v; i--) ans -= cnt[x][i];
		lazy[x] -= v;
	}
}

void rebuild(int x, int L, int R, int v)
{
	int l = x * T, r = std::min(n - 1, (x + 1) * T - 1);
	
	for(int i = l; i <= r; i++) 
	{
		if(used[rdfn[i]]) continue;
		cnt[x][a[rdfn[i]]]--;
		if(a[rdfn[i]] < lazy[x]) ans--;
	}
	
	for(int i = l; i <= r; i++) a[rdfn[i]] -= (lazy[x] - Max); 
	lazy[x] = Max;
	for(int i = L; i <= R; i++) a[rdfn[i]] += v;
	
	for(int i = l; i <= r; i++) 
	{
		if(used[rdfn[i]]) continue;
		cnt[x][a[rdfn[i]]]++;
		if(a[rdfn[i]] < lazy[x]) ans++;
	}
}

void modify(int l, int r, int v)
{
	int lb = l / T, rb = r / T;
	if(lb == rb) rebuild(lb, l, r, v);
	else
	{
		for(int j = lb + 1; j < rb; j++) add(j, v);
		rebuild(lb, l, std::min(n - 1, (lb + 1) * T - 1), v);
		rebuild(rb, rb * T, r, v);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 2; i <= n; i++)
	{
		scanf("%d", &fa[i]);
		ins(fa[i], i);
	}
	dfs1(1); dfs2(1, 1);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] += Max;
	for(int i = 0; i <= (n - 1) / T; i++) init(i);
	for(int i = 1; i <= m; i++)
	{
		int x, v = -1; scanf("%d", &x);
		if(x < 0)
		{
			x = -x, v = 1;
			used[x] = 0;
			int id = dfn[x] / T;
			if(a[x] < lazy[id]) ans++;
			cnt[id][a[x]]++;
		}
		else
		{
			used[x] = 1;
			int id = dfn[x] / T;
			if(a[x] < lazy[id]) ans--;
			cnt[id][a[x]]--;
		}
		int k;
		for(int j = x; j; j = fa[k])
		{
			k = top[j];
			modify(dfn[k], dfn[j], v);
		}
		printf("%d ", ans);
	}
}