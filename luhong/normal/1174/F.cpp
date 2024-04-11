#include <cstdio>
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#define MN 201000

int n;
int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
int dep[MN], fa[MN];
int a[MN], tot = 0, w;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void dfs(int x, int f, int d)
{
	dep[x] = d; fa[x] = f;
	for(int i = h[x]; i; i = nxt[i])
		if(to[i] != f) dfs(to[i], x, d + 1);
}

void dfs2(int x, int d)
{
	if(d == w) a[++tot] = x;
	for(int i = h[x]; i; i = nxt[i])
		if(to[i] != fa[x]) dfs2(to[i], d + 1);
}

int main()
{
	srand((int)time(0));
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		ins(a, b); ins(b, a);
	}
	dfs(1, 0, 0);
	printf("d 1\n"); fflush(stdout);
	int D; scanf("%d", &D);
	int now = 1;
	while(dep[now] != D)
	{
		w = D - dep[now]; tot = 0;
		dfs2(now, 0);
		long long v = ( 1ll * rand() * RAND_MAX + rand() ) % tot + 1;
		printf("d %d\n", a[v]); fflush(stdout);
		int o; scanf("%d", &o);
		for(int i = 1; i <= o / 2; i++) a[v] = fa[a[v]];
		now = a[v];
		if(dep[now] == D) break;
		printf("s %d\n", now); fflush(stdout);
		scanf("%d", &now);
	}
	printf("! %d\n", now); fflush(stdout);
}