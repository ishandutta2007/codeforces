#include <cstdio>
#include <cstring>
#define MN 401000

int h[MN], nxt[2 * MN], to[2 * MN], id[2 * MN], K = 0;
int ans[MN], iter[MN];

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; id[K] = c;}

void dfs(int x, int c)
{
	while(iter[x] && ans[id[iter[x]]] != -1) iter[x] = nxt[iter[x]];
	if(iter[x])
	{
		int i = iter[x]; ans[id[i]] = c; 
		iter[x] = nxt[iter[x]];
		dfs(to[i], c ^ 1);
	}
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		ins(x, y + 200000, i); ins(y + 200000, x, i);
	}
	memcpy(iter, h, sizeof(h));
	memset(ans, -1, sizeof(ans));
	for(int i = 1; i <= 200000; i++)
	{
		int c = 0;
		while(iter[i]) dfs(i, c), c ^= 1;
	}
	for(int i = 1; i <= n; i++) printf(ans[i] ? "b" : "r");
}