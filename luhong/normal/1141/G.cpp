#include <cstdio>
#include <iostream>
#include <algorithm>
#define MN 201000

int h[MN], nxt[2 * MN], to[2 * MN], id[2 * MN], K = 0;
int d[MN], p[MN], c;
int Ans[MN];

void ins(int u, int v, int i) {nxt[++K] = h[u]; h[u] = K; to[K] = v; id[K] = i;}

bool cmp(int a, int b) {return d[a] > d[b];}

void dfs(int x, int fa, int col)
{
	int tot = 0;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		if(d[x] > c) Ans[id[i]] = 1;
		else
		{
			++tot;
			if(tot == col) ++tot;
			Ans[id[i]] = tot;
		}
		dfs(to[i], x, Ans[id[i]]);
	}
}

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 1; i < n; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v, i); ins(v, u, i);
		d[u]++; d[v]++;
	}
	
	for(int i = 1; i <= n; i++) p[i] = i;
	
	std::sort(p + 1, p + n + 1, cmp);
	
	c = d[p[k + 1]];
	
	dfs(1, 0, 0);
	
	printf("%d\n", c);
	for(int i = 1; i < n; i++) printf("%d ", Ans[i]);
}