#include <cstdio>
#include <algorithm>
#define MN 501000

int st[MN][20];
int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
long long ans = 0; int rt, a[MN]; 

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void dfs1(int x, int f)
{
	st[x][0] = f;
	for(int i = 1; i <= 19; i++)
		st[x][i] = st[st[x][i - 1]][i - 1];
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == f) continue;
		dfs1(to[i], x);
	}
}

void dfs2(int x)
{
	if(x != rt)
	{
		long long Min = 1e18;
		for(int i = 0; i <= 19; i++)
		{
			int u = st[x][i]; 
			if(u == 0) u = rt;
			Min = std::min(Min, 1ll * i * a[u] + a[x] + a[u]);
		}
		ans += Min;
	}
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == st[x][0]) continue;
		dfs2(to[i]);
	}
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(rt == 0 || a[i] < a[rt]) rt = i; 
	}
	for(int i = 1; i < n; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v); ins(v, u); 
	}
	dfs1(rt, 0);
	dfs2(rt);
	printf("%lld\n", ans);
	return 0;
}


/*
2^i
au + av
*/