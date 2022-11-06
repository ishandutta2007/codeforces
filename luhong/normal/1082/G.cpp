#include <cstdio>
#include <iostream>
#include <cstring>
#define MN 2500
#define int long long

int h[MN], nxt[201000], to[201000], cap[201000], K = 1;
int level[MN], iter[MN], hh, tt, q[201000];

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cap[K] = c;}

void insw(int u, int v, int c) {ins(u, v, c); ins(v, u, 0);}

int bfs(int S, int T)
{
    hh = tt = 0; q[tt++] = S; memset(level,0,sizeof(level)); level[S] = 1;
    while(hh < tt)
    {
        int u = q[hh++]; iter[u] = h[u];
        for(int i=h[u]; i; i=nxt[i])
        {
            if(cap[i] && !level[to[i]])
            {
                level[to[i]] = level[u] + 1;
                q[tt++] = to[i];
            }
        }
    }
    return level[T]; 
}

int dfs(int u, int f, int T)
{
    if(u == T) return f;
    int used = 0, w;
    for(int &i = iter[u]; i; i=nxt[i])
    {
        if(cap[i] && level[to[i]] == level[u] + 1)
        {
            w = dfs(to[i], std::min(f - used, cap[i]), T);
            if(w)
            {
                cap[i] -= w; cap[i^1] += w; used += w; if(used == f) return f;
            }
        }
    }
    return used;
}

int dinic(int S, int T)
{
    int f = 0;
    while(bfs(S, T)) f += dfs(S, 1e18, T);
    return f;
}

signed main()
{
    int n, m; scanf("%lld%lld", &n, &m);
    int S = n + m + 1, T = n + m + 2;
	for(int i = 1; i <= n; i++)
    {
    	long long a;
    	scanf("%lld", &a);
    	insw(i, T, a);
	}
	int id = n;
	long long ans = 0;
	for(int i = 1; i <= m; i++)
	{
		int u, v, a; scanf("%lld%lld%lld", &u, &v, &a);
		++id; insw(id, u, 1e18); insw(id, v, 1e18);
		insw(S, id, a); ans += a;
	}
    printf("%lld\n", ans - dinic(S,T));
	return 0;
}