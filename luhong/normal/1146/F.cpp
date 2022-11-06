#include <cstdio>
#include <iostream>
#define MN 201000
#define mod 998244353

int f[MN], g[MN];
int h[MN], nxt[2 * MN], to[2 * MN], K = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

int qpow(int x, int p)
{
	int ans = 1;
	while(p)
	{
		if(p & 1) ans = 1ll * ans * x % mod;
		x = 1ll * x * x % mod; p >>= 1;
	}
	return ans;
}

void dfs(int x)
{
	bool ok = 0;
	f[x] = g[x] = 1;
	int G = 0;
	for(int i = h[x]; i; i = nxt[i])
	{
		ok = 1;
		dfs(to[i]);
		f[x] = 1ll * f[x] * (f[to[i]] + g[to[i]]) % mod;
		g[x] = 1ll * g[x] * f[to[i]] % mod; 
	}
	for(int i = h[x]; i; i = nxt[i]) G = (G + 1ll * g[x] * qpow(f[to[i]], mod - 2) % mod * g[to[i]]) % mod;
	if(ok) g[x] = (f[x] - g[x] + mod) % mod, f[x] = (f[x] - G + mod) % mod;
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 2; i <= n; i++) 
	{
		int p; scanf("%d", &p);
		ins(p, i);
	}
	dfs(1); printf("%d\n", f[1]);
}