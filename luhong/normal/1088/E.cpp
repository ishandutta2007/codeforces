#include <cstdio>
#include <algorithm>
#define MN 501000

int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
long long Max = -1e18;
long long a[MN]; int ans = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

long long dfs1(int x, int fa)
{
	long long sum = a[x];
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		sum += dfs1(to[i], x);
	}
	sum = std::max(sum, a[x]);
	Max = std::max(Max, sum);
	return std::max(sum, 0ll);
}

long long dfs2(int x, int fa)
{
	long long sum = a[x];
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		sum += dfs2(to[i], x);
	}
	sum = std::max(sum, a[x]);
	if(sum == Max) {ans++; return 0;}
	return std::max(sum, 0ll);
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i < n; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v); ins(v, u); 
	}
	dfs1(1, 0);
	dfs2(1, 0);
	printf("%lld %d\n", Max * ans, ans);
	return 0;
}


/*
K = 1
 
*/