#include <cstdio>
#include <iostream>
#define MN 201000

int f[MN][1 << 6];
int pri[MN], tot = 0;
bool ok[MN];
int n;
int v[MN][7], a[MN];
int len[MN];

void init()
{
	for(int i = 2; i <= 200000; i++)
	{
		if(!ok[i]) {pri[++tot] = i;}
		for(int j = 1; j <= tot && i * pri[j] <= 200000; j++)
		{
			ok[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

int Max[MN];
bool used[MN];
int wz[MN];
int ans = 0;
int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void dfs(int x, int fa)
{
	for(int i = h[x]; i; i = nxt[i]) if(to[i] != fa) dfs(to[i], x);
	
	f[x][(1 << len[x]) - 1] = 1;
	
	for(int i = 1; i <= len[x]; i++) Max[v[x][i]] = 0, used[v[x][i]] = 1, wz[v[x][i]] = i;
	
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		for(int S = 0; S < (1 << len[to[i]]); S++)
		{
			int SS = 0;
			for(int j = 1; j <= len[to[i]]; j++)
			{
				if((S >> j - 1) & 1)
				{
					if(used[v[to[i]][j]])
					{
						ans = std::max(ans, f[to[i]][S] + Max[v[to[i]][j]] + 1);
						SS |= (1 << wz[v[to[i]][j]] - 1); 
					}
				}
			}
			f[x][SS] = std::max(f[x][SS], f[to[i]][S] + 1);
		}
		
		for(int S = 0; S < (1 << len[to[i]]); S++)
		{
			for(int j = 1; j <= len[to[i]]; j++)
				if((S >> j - 1) & 1)
					if(used[v[to[i]][j]])
						Max[v[to[i]][j]] = std::max(Max[v[to[i]][j]], f[to[i]][S]);
		}
	}
	
	for(int i = 1; i <= len[x]; i++) used[v[x][i]] = 0;
}

int main()
{
	scanf("%d", &n);
	init();
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] != 1) ans = 1;
	}
	for(int i = 1; i < n; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v); ins(v, u);
	}
	for(int i = 1; i <= n; i++)
	{
		int w = a[i];
		for(int j = 1; pri[j] * pri[j] <= a[i]; j++)
		{
			bool ok = 0;
			while(w % pri[j] == 0)
			{
				w /= pri[j];
				ok = 1;
			}
			if(ok) v[i][++len[i]] = pri[j];
		}
		if(w != 1) v[i][++len[i]] = w;
	}
	dfs(1, 0);
	printf("%d\n", ans);
}