#include <iostream>
#include <cstdio>
#define MN 1010000
#define mod 1000000007

int h[MN], nxt[2 * MN], to[2 * MN], K = 1;
int son[MN], siz[MN];
int st[MN], top = 0;
int ans[MN], o = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;} 

void dfs(int x)
{
	for(int i = h[x]; i; i = nxt[i])
	{
		dfs(to[i]);
		if(siz[son[x]] < siz[to[i]]) son[x] = to[i];
	}
	siz[x] = siz[son[x]] + 1;
}

void dfs3(int x)
{
	ans[++o] = st[top];
	for(int i = h[x]; i; i = nxt[i])
	{
		dfs3(to[i]);
	}
	st[++top] = x;
}

void dfs2(int x)
{
	if(son[x]) dfs2(son[x]);
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] != son[x]) dfs3(to[i]);
	}
	st[++top] = x;
}

int main()
{
	siz[0] = -1; int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++)
	{
		int p; scanf("%d", &p);
		p++;
		ins(p, i);
	}
	dfs(1); dfs2(1);
	for(int i = top; i >= 1; i--) printf("%d ", st[i] - 1); puts("");
	printf("%d\n", o);
	for(int i = o; i >= 1; i--) printf("%d ", ans[i] - 1); puts("");
}