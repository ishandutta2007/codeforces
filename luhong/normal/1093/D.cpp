#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring> 
#define MN 301000
#define mod 998244353

int h[MN], nxt[MN * 2], to[MN * 2], K = 0;
bool flag = 0;
int col[MN], w, b;

void dfs(int x)
{
	if(col[x] == 0) w++;
	else b++;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(col[to[i]] == -1)
		{
			col[to[i]] = col[x] ^ 1;
			dfs(to[i]);
		}
		else
		{
			if(col[to[i]] == col[x]) flag = 1;
		}
	}
}
void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n, m; scanf("%d%d", &n, &m);
		K = 0; for(int i = 1; i <= n; i++) h[i] = 0, col[i] = -1; flag = 0;
		for(int i = 1; i <= m; i++)
		{
			int u, v; scanf("%d%d", &u, &v);
			ins(u, v); ins(v, u);
		}
		long long ans = 1;
		for(int i = 1; i <= n; i++)
		{
			if(col[i] == -1)
			{
				int s1 = 1, s2 = 1;
				w = b = 0; col[i] = 0;
				dfs(i);
				for(int j = 1; j <= w; j++) s1 = s1 * 2 % mod;
				for(int j = 1; j <= b; j++) s2 = s2 * 2 % mod;
				ans = ans * (s1 + s2) % mod;
			}
		}
		if(flag) puts("0");
		else printf("%lld\n", ans);
	}
	return 0;
}