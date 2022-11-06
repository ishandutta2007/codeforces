#include <iostream>
#include <cstdio>
#define mod 1000000007
#define MN 101000
 
int c1[MN], c2[MN], c3[MN], c4[MN];
int S = 1, ans = 0;
int l[MN], r[MN], dep[MN], siz[MN], son[MN];
int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
 
void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}
 
void add(int *c, int x, int v) {for(int i = x; i <= 100000; i += i & -i) c[i] = (c[i] + v) % mod;}
int query(int *c, int x) {int ans = 0; for(int i = x; i; i -= i & -i) ans = (ans + c[i]) % mod; return ans;}
 
void ADD(int x, int v, int ty)
{
	if(ty == 0)
	{
		add(c1, x, 1ll * x * v % mod);
		add(c2, x, v);
	}
	else
	{
		add(c3, x, 1ll * x * v % mod);
		add(c4, x, v);
	}
}
 
void Add(int l, int r, int v, int ty)
{
	if(l - 1 > 0) ADD(l - 1, (-v + mod) % mod, ty);
	ADD(r, v, ty);
}
 
int QUERY(int x, int ty)
{
	if(ty == 0) return (query(c1, x) + 1ll * x * (query(c2, 100000) - query(c2, x) + mod)) % mod; 
	return (query(c3, x) + 1ll * x * (query(c4, 100000) - query(c4, x) + mod)) % mod; 
}
 
int Query(int l, int r, int ty)
{
	return (QUERY(r, ty) - QUERY(l - 1, ty) + mod) % mod;
}
 
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
 
void init(int x, int fa)
{
	dep[x] = dep[fa] + 1; siz[x] = 1;
	for(int i = h[x]; i; i = nxt[i]) 
		if(to[i] != fa)
		{
			init(to[i], x);
			siz[x] += siz[to[i]];
			if(siz[to[i]] > siz[son[x]]) son[x] = to[i];
		}
}
 
void dfs3(int x, int fa, int w)
{
	int len = qpow(r[x] - l[x] + 1, mod - 2);
	ans = (ans + 1ll * Query(l[x], r[x], 0) * len) % mod;
	ans = (ans + 1ll * Query(l[x], r[x], 1) * (dep[x] - 2 * w + mod) % mod * len) % mod;
	
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] != fa)
			dfs3(to[i], x, w);
	}
}
 
void dfs4(int x, int fa, int ty)
{
	int len = qpow(r[x] - l[x] + 1, mod - 2);
	if(!ty)
	{
		Add(l[x], r[x], 1ll * dep[x] * S % mod * len % mod, 0);
		Add(l[x], r[x], 1ll * S * len % mod, 1);
	}
	else
	{
		Add(l[x], r[x], (mod - 1ll * dep[x] * S % mod * len % mod) % mod, 0);
		Add(l[x], r[x], (mod - 1ll * S * len % mod) % mod, 1);
	}
	
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] != fa)
			dfs4(to[i], x, ty);
	}
}
 
void dfs(int x, int fa, int ok)
{
	for(int i = h[x]; i; i = nxt[i])
		if(to[i] != son[x] && to[i] != fa) dfs(to[i], x, 0);
	if(son[x]) dfs(son[x], x, 1);
	
	int w = dep[x];
	
	int len = qpow(r[x] - l[x] + 1, mod - 2);
	ans = (ans + 1ll * Query(l[x], r[x], 0) * len) % mod;
	ans = (ans + 1ll * Query(l[x], r[x], 1) * (dep[x] - 2 * w + mod) % mod * len) % mod;
	Add(l[x], r[x], 1ll * dep[x] * S % mod * len % mod, 0);
	Add(l[x], r[x], 1ll * S * len % mod, 1);
	
	for(int i = h[x]; i; i = nxt[i])
		if(to[i] != son[x] && to[i] != fa)
		{
			dfs3(to[i], x, w);
			dfs4(to[i], x, 0);
		}
		
	if(!ok) dfs4(x, fa, 1);
}
 
int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		S = 1ll * S * (r[i] - l[i] + 1) % mod;
	}
	for(int i = 1; i < n; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v); ins(v, u);
	}
	init(1, 0);
	dfs(1, 0, 1);
	printf("%d\n", ans);
 }