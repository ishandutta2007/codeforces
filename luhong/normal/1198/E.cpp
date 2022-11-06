#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MN 510
#define MM 25010
 
int h[MN], nxt[MM], to[MM], cap[MM], K = 1;
int q[MN], hh = 0, tt = 0, lvl[MN], iter[MN];
int bx[MN], by[MN]; 
int a[MN], b[MN], c[MN], d[MN];
 
void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cap[K] = c;}
 
void insw(int u, int v, int c) {ins(u, v, c); ins(v, u, 0);}
 
bool bfs(int S, int T)
{
	hh = tt = 0;
	memset(lvl, 0, sizeof(lvl));
	lvl[T] = 1;
	q[tt++] = T;
	while(hh < tt)
	{
		int u = q[hh++]; iter[u] = h[u];
		for(int i = h[u]; i; i = nxt[i])
		{
			if(cap[i ^ 1] && !lvl[to[i]]) 
			{
				lvl[to[i]] = lvl[u] + 1;
				q[tt++] = to[i];
			} 
		}
	}
	return lvl[S] != 0;
}
 
int dfs(int u, int T, int f)
{
	if(u == T) return f;
	int used = 0, w;
	for(int &i = iter[u]; i; i = nxt[i])
	{
		if(cap[i] && lvl[to[i]] == lvl[u] - 1)
		{
			w = dfs(to[i], T, std::min(f - used, cap[i]));
			if(w) {cap[i] -= w; cap[i ^ 1] += w; used += w; if(used == f) return f;} 
		}
	}
	return used;
}
 
int dinic(int S, int T)
{
	int flow = 0;
	while(bfs(S, T))
	{
		int f;
		do {
			flow += (f = dfs(S, T, 2e9));
		} while(f);
	}
	return flow;
}
 
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	int totx = 0, toty = 0;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
		bx[++totx] = a[i]; by[++toty] = b[i];
		bx[++totx] = c[i] + 1; by[++toty] = d[i] + 1;
	}
	std::sort(bx + 1, bx + totx + 1); totx = std::unique(bx + 1, bx + totx + 1) - bx - 1;
	std::sort(by + 1, by + toty + 1); toty = std::unique(by + 1, by + toty + 1) - by - 1; 
	int S = totx + toty + 2 * m + 1, T = S + 1;
	for(int i = 1; i < totx; i++) insw(S, i, bx[i + 1] - bx[i]);
	for(int i = 1; i < toty; i++) insw(i + totx, T, by[i + 1] - by[i]);
	for(int i = 1; i <= m; i++)
	{
		int l = std::lower_bound(bx + 1, bx + totx + 1, a[i]) - bx;
		int r = std::lower_bound(bx + 1, bx + totx + 1, c[i] + 1) - bx;
		int id = totx + toty + 2 * i - 1; 
		for(int j = l; j < r; j++) insw(j, id, 1e9);
		
		l = std::lower_bound(by + 1, by + toty + 1, b[i]) - by;
		r = std::lower_bound(by + 1, by + toty + 1, d[i] + 1) - by;
		for(int j = l; j < r; j++) insw(id + 1, j + totx, 1e9);
		
		insw(id, id + 1, 1e9);
	}
	printf("%d\n", dinic(S, T));
}