#include <iostream>
#include <cstdio>
#include <cstring>
#define MN 110
#define MM 1100

int h[MN], nxt[MM], to[MM], cap[MM], cost[MM], K = 1;
int d[MN], ans = 0, iter[MN];
bool vis[MN];

void ins(int u, int v, int ca, int co) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cap[K] = ca; cost[K] = co;}
void insw(int u, int v, int ca, int co) {ins(u, v, ca, co); ins(v, u, 0, -co);}

int Bellman_Ford(int S, int T)
{
	memcpy(iter, h, sizeof(h));
	memset(d, 0x3f, sizeof(d));
	d[S] = 0;
	for(int o = 1; o < T; o++)
		for(int u = 1; u <= T; u++)
			for(int i = h[u]; i; i = nxt[i])
				if(cap[i]) d[to[i]] = std::min(d[to[i]], d[u] + cost[i]);
	if(d[T] == d[0]) return 0;
	return 1; 
}

int dfs(int u, int T, int f)
{
	if(u == T) return f;
	int used = 0; vis[u] = 1;
	for(int &i = iter[u]; i; i = nxt[i])
	{
		if(!vis[to[i]] && cap[i] && d[to[i]] == d[u] + cost[i])
		{
			int w = dfs(to[i], T, std::min(f - used, cap[i]));
			if(w)
			{
				cap[i] -= w; cap[i ^ 1] += w; ans += w * cost[i]; used += w;
				if(used == f) return f;
			}
		}
	}
	return used;
}

void zkw(int S, int T)
{
	while(Bellman_Ford(S, T))
	{
		memset(vis, 0, sizeof(vis));
		while(dfs(S, T, 1e9)) memset(vis, 0, sizeof(vis));
	}
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	int S = n + 1, T = S + 1;
	for(int i = 1; i <= m; i++)
	{
		int u, v, c, f; scanf("%d%d%d%d", &u, &v, &c, &f);
		insw(S, v, f, 0); insw(u, T, f, 0);
		if(f <= c)
		{
			insw(u, v, c - f, 1);
			insw(u, v, 1e9, 2);
			insw(v, u, f, 1);
		}
		else
		{
			ans += f - c;
			insw(u, v, 1e9, 2);
			insw(v, u, f - c, 0);
			insw(v, u, c, 1);
		}
	}
	insw(n, 1, 1e9, 0);
	zkw(S, T);
	printf("%d\n", ans);
}