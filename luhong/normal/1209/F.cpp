#include <iostream>
#include <cstdio>
#include <algorithm>
#define mod 1000000007 
#define MN 1510000

int h[MN], nxt[2 * MN], to[2 * MN], cost[2 * MN], K = 0;
int rk[MN], d[MN], q[MN], vis[MN];

bool cmp(int a, int b) {return rk[a] < rk[b];}

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cost[K] = c;}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	int tot = n;
	for(int i = 1; i <= m; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		
		int X = x, Y = y, j = i;
		while(i >= 10) ++tot, ins(tot, y, i % 10), i /= 10, y = tot;
		ins(x, y, i);
		
		x = X, y = Y, i = j;
		while(i >= 10) ++tot, ins(tot, x, i % 10), i /= 10, x = tot;
		ins(y, x, i);
		
		i = j;
	}
	
	int hh = 0, tt = -1; q[++tt] = 1; vis[1] = 1; d[1] = rk[1] = 0;
	while(hh <= tt)
	{
		int H = hh, T = tt; hh = T + 1;
		for(int j = H; j <= T; j++)
		{
			int u = q[j];
			for(int i = h[u]; i; i = nxt[i])
			{
				if(!vis[to[i]] || vis[to[i]] == vis[u] + 1 && rk[to[i]] > rk[u] * 10 + cost[i])
				{
					if(!vis[to[i]]) q[++tt] = to[i];
					vis[to[i]] = vis[u] + 1;
					d[to[i]] = (d[u] * 10ll + cost[i]) % mod; 
					rk[to[i]] = rk[u] * 10 + cost[i];
				}
			}
		}
		std::sort(q + hh, q + tt + 1, cmp);
		int k = 0, lst = rk[q[hh]]; rk[q[hh]] = k;
		for(int i = hh + 1; i <= tt; i++)
		{
			if(rk[q[i]] != lst) k++;
			lst = rk[q[i]]; rk[q[i]] = k;
		}
	} 
	
	for(int i = 2; i <= n; i++) printf("%d\n", d[i]);
}