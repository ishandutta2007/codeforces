#include <cstdio>
#include <cstring>
#include <iostream>
#define MN 3010
#define MM 1010000

int h[MN], nxt[MM], to[MM], cap[MM], K = 1;
int lvl[MN], iter[MN], q[MN];

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cap[K] = c;}
void insw(int u, int v, int c) {ins(u, v, c); ins(v, u, 0);}

bool bfs(int S, int T)
{
    int hh = 0, tt = 0;
    q[tt++] = S;
    memset(lvl, -1, sizeof(lvl));
    lvl[S] = 0;
    while(hh < tt)
    {
        int u = q[hh++]; iter[u] = h[u];
        for(int i = h[u]; i; i = nxt[i])
        {
            if(cap[i] && lvl[to[i]] == -1)
            {
                lvl[to[i]] = lvl[u] + 1;
            	q[tt++] = to[i]; 
			}
        }
    }
    if(lvl[T] == -1) return 0;
    return 1;
}

int dfs(int u, int T, int f)
{
	if(u == T) return f;
	int used = 0;
	for(int &i = iter[u]; i; i = nxt[i])
	{
		if(cap[i] && lvl[to[i]] == lvl[u] + 1)
		{
			int w = dfs(to[i], T, std::min(cap[i], f - used)); 
			if(w) 
			{
				cap[i] -= w; cap[i ^ 1] += w;
				used += w; if(used == f) return f;
			}
		}
	}
	return used;
}

int dinic(int S, int T)
{
	int f = 0;
	while(bfs(S, T)) f += dfs(S, T, 1e9);
	return f;
}

int main()
{
	int n, h, m; scanf("%d%d%d", &n, &h, &m);
	int S = n * (h + 1) + m, T = S + 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < h; j++)
		{
			if(j == 0) insw(S, (i - 1) * (h + 1), 1e9);
			insw((i - 1) * (h + 1) + j, (i - 1) * (h + 1) + j + 1, h * h - j * j);
		}
	for(int i = 0; i < m; i++)
	{
		int l, r, x, c; scanf("%d%d%d%d", &l, &r, &x, &c);
		if(x < h)
		{
			insw(n * (h + 1) + i, T, c);
			for(int j = l; j <= r; j++)
				insw((j - 1) * (h + 1) + x + 1, n * (h + 1) + i, 1e9);
		}
	}
	printf("%d\n", n * h * h - dinic(S, T));
}