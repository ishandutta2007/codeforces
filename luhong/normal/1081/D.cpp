#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring> 
#define mod 998244353
#define MN 201000

struct xxx{
	int u, v, c;
}e[MN];

int h[MN], nxt[MN], to[MN], K = 0, cost[MN];
int n, m, fa[MN], d[MN];
bool used[MN];

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cost[K] = c;}

int Find(int x) {return fa[x] == x ? x : fa[x] = Find(fa[x]);}

bool cmp(xxx a, xxx b) {return a.c < b.c;}

void Kruskal()
{
	std::sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= m; i++)
	{
		if(Find(e[i].u) != Find(e[i].v))
		{
			fa[Find(e[i].u)] = Find(e[i].v);
			ins(e[i].u, e[i].v, e[i].c);
			ins(e[i].v, e[i].u, e[i].c); 
			d[e[i].v]++; d[e[i].u]++;
		}
	}
}

int ans = 0; bool vis[MN];
void dfs(int x, int fa)
{
	if(vis[x]) return;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa || vis[to[i]]) continue;
		ans = std::max(ans, cost[i]);
		dfs(to[i], x);
	}
}

int q[MN];
int main()
{
	int k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= k; i++) {int a; scanf("%d", &a); used[a] = 1;}
	for(int i = 1; i <= m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
	Kruskal();
	int hh = 0, tt = 0;
	for(int i = 1; i <= n; i++) if(d[i] == 1) q[tt++] = i;
	while(hh < tt)
	{
		int x = q[hh++];
		if(used[x]) continue;
		vis[x] = 1;
		for(int i = h[x]; i; i = nxt[i])
			if(--d[to[i]] == 1)
				q[tt++] = to[i];
	}
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i]) {dfs(i, 0); break;}
	}
	for(int i = 1; i <= k; i++) printf("%d ", ans);
	return 0;
}