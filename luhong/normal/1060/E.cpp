#include <cstdio>
#include <iostream>

using namespace std;

int n; long long ans = 0;
int siz[201000];
int k1, k2;
int dep[201000];
int h[201000], nxt[401000], to[401000], K = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void dfs(int x, int fa, int d)
{
	siz[x] = 1; dep[x] = d;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		dfs(to[i], x, d + 1); siz[x] += siz[to[i]];
	}
	ans += 1ll * siz[x] * (n - siz[x]);
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v); ins(v, u);
	}
	dfs(1, 0, 1);
	for(int i = 1; i <= n; i++) 
	{
		if(dep[i] & 1) k1++;
		else k2++;
	}
	printf("%lld\n", (ans + 1ll * k1 * k2) / 2);
	return 0;
}