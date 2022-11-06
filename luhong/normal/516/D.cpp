#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MN 101000

typedef long long ll;

int h[MN], nxt[2 * MN], to[2 * MN], cost[2 * MN], K = 0;
ll d[MN], a[MN];
int dfn[MN], siz[MN], D = 0;
int c[MN], p[MN]; int n; 

bool cmp(int a, int b) {return d[a] == d[b] ? dfn[a] > dfn[b] : d[a] > d[b];}

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cost[K] = c;}

void add(int x, int v) {for(int i = x; i <= n; i += i & -i) c[i] += v;}
int query(int x) {int ans = 0; for(int i = x; i; i -= i & -i) ans += c[i]; return ans;}

void dfs(int x, int fa)
{
	for(int i = h[x]; i; i = nxt[i])
		if(to[i] != fa) d[to[i]] = d[x] + cost[i], dfs(to[i], x);
}

void dfs2(int x, int fa)
{
	dfn[x] = ++D; siz[x] = 1;
	for(int i = h[x]; i; i = nxt[i])
		if(to[i] != fa) dfs2(to[i], x), siz[x] += siz[to[i]];
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		ins(u, v, w); ins(v, u, w);
	}
	d[1] = 0; dfs(1, 0);
	int id = 0;
	for(int i = 1; i <= n; i++) if(d[i] > d[id]) id = i; 
	d[id] = 0; dfs(id, 0);
	memcpy(a, d, sizeof(d));
	id = 0;
	for(int i = 1; i <= n; i++) if(d[i] > d[id]) id = i;
	d[id] = 0; dfs(id, 0);
	for(int i = 1; i <= n; i++) d[i] = std::max(d[i], a[i]);
	id = 0; d[0] = 1e18;
	for(int i = 1; i <= n; i++) if(d[i] < d[id]) id = i;
	dfs2(id, 0);
	for(int i = 1; i <= n; i++) p[i] = i;
	std::sort(p + 1, p + n + 1, cmp);
	int q; scanf("%d", &q);
	while(q--)
	{
		ll x; scanf("%lld", &x); 
		int j = 1, ans = 0;
		for(int I = 1; I <= n; I++)
		{
			int i = p[I];
			add(dfn[i], 1);
			while(d[p[j]] - d[i] > x) add(dfn[p[j++]], -1);
			ans = std::max(ans, query(dfn[i] + siz[i] - 1) - query(dfn[i] - 1));
		}
		memset(c, 0, sizeof(c));
		printf("%d\n", ans);
	}
}