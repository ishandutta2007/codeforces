#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define MN 2010
#define MM 101000

typedef long long ll;

int h[MN], nxt[2 * MM], to[2 * MM], cost[2 * MM], K = 0;
ll v[MN][MN][2], f[MN][MN][2];
int w[MN];
ll d[2][MN]; bool used[MN];
ll b[2][MN];
int n, m, s, t; 

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cost[K] = c;}

void dij(ll *d, int S)
{
	memset(used, 0, sizeof(used));
	d[S] = 0; 
	for(int T = 1; T <= n; T++)
	{
		int u = 0;
		for(int i = 1; i <= n; i++)
			if(!used[i] && (u == 0 || d[i] < d[u])) u = i;
		used[u] = 1;
		for(int i = h[u]; i; i = nxt[i])
			d[to[i]] = std::min(d[to[i]], d[u] + cost[i]);
	}
}

int main()
{
	memset(d, 0x3f, sizeof(d));
	memset(v, 0x3f, sizeof(v)); ll inf = v[0][0][0];
	memset(f, 0, sizeof(f));
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= m; i++) 
	{
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		ins(u, v, w); ins(v, u, w);
	}
	dij(d[0], s); dij(d[1], t);
	memcpy(b, d, sizeof(d));
	int N[2];
	for(int i = 0; i < 2; i++)
	{
		std::sort(b[i] + 1, b[i] + n + 1); N[i] = std::unique(b[i] + 1, b[i] + n + 1) - b[i] - 1;
		for(int j = 1; j <= n; j++) d[i][j] = std::lower_bound(b[i] + 1, b[i] + N[i] + 1, d[i][j]) - b[i];
	}
	
	for(int j = 0; j <= N[1]; j++)
		for(int i = 1; i <= n; i++)
		{
			if(d[1][i] > j)
			{
				if(v[d[0][i]][j][0] == inf) v[d[0][i]][j][0] = 0;
				v[d[0][i]][j][0] += w[i];
			}
		}

	for(int j = 0; j <= N[0]; j++)
		for(int i = 1; i <= n; i++)
		{
			if(d[0][i] > j)
			{
				if(v[j][d[1][i]][1] == inf) v[j][d[1][i]][1] = 0;
				v[j][d[1][i]][1] += w[i];
			}
		}
	
	for(int i = N[0]; i >= 0; i--)
		for(int j = N[1]; j >= 0; j--)
		{
			if(v[i + 1][j][0] == inf) f[i][j][0] = f[i + 1][j][0];
			else f[i][j][0] = std::max(f[i + 1][j][0], f[i + 1][j][1]) + v[i + 1][j][0];
			
			if(v[i][j + 1][1] == inf) f[i][j][1] = f[i][j + 1][1];
			else f[i][j][1] = std::min(f[i][j + 1][1], f[i][j + 1][0]) - v[i][j + 1][1];
		}
		
	if(f[0][0][0] > 0) puts("Break a heart");
	if(f[0][0][0] == 0) puts("Flowers");
	if(f[0][0][0] < 0) puts("Cry"); 
}