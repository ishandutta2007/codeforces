#include <iostream>
#include <cstdio>
#include <cstring>
#define MN 501000

int dep[MN], f[MN], mx[1 << 22], v[MN];
int h[MN], nxt[2 * MN], to[2 * MN], cost[2 * MN], K = 0;
int siz[MN], son[MN];

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cost[K] = c;}

void del(int x)
{
	mx[v[x]] = -1e9;
	for(int i = h[x]; i; i = nxt[i]) del(to[i]);
}

void add(int x)
{
	mx[v[x]] = std::max(dep[x], mx[v[x]]);
	for(int i = h[x]; i; i = nxt[i]) add(to[i]);
}

int upd(int x)
{
	int ans = mx[v[x]];
	for(int i = 0; i < 22; i++) ans = std::max(ans, mx[v[x] ^ (1 << i)]);
	return ans;
}

int rw(int x)
{
	int ans = dep[x] + upd(x);
	for(int i = h[x]; i; i = nxt[i]) ans = std::max(ans, rw(to[i]));
	return ans;
}

void dfs(int x, bool ok)
{
	for(int i = h[x]; i; i = nxt[i])
		if(to[i] != son[x]) dfs(to[i], 0), f[x] = std::max(f[x], f[to[i]]);
	
	if(son[x]) dfs(son[x], 1);
	if(son[x]) f[x] = std::max(f[x], f[son[x]]);
	
	f[x] = std::max(f[x], dep[x] + upd(x) - 2 * dep[x]);
	mx[v[x]] = std::max(dep[x], mx[v[x]]);
	
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == son[x]) continue;
		f[x] = std::max(rw(to[i]) - 2 * dep[x], f[x]);
		add(to[i]);
	}
	
	if(!ok) del(x);
}

void init(int x, int d)
{ 
	dep[x] = d; siz[x] = 1;
	for(int i = h[x]; i; i = nxt[i])
	{
		v[to[i]] = v[x] ^ (1 << cost[i]);
		init(to[i], d + 1);
		siz[x] += siz[to[i]];
		if(siz[to[i]] > siz[son[x]]) son[x] = to[i];
	}
}

int main()
{
	memset(mx, -0x3f, sizeof(mx));
	int n; scanf("%d", &n);
	for(int i = 2; i <= n; i++)
	{
		int f; char s[2]; scanf("%d%s", &f, s);
		ins(f, i, s[0] - 'a');
	}
	init(1, 0);
	dfs(1, 1);
	for(int i = 1; i <= n; i++) printf("%d ", f[i]);
	return 0;
}