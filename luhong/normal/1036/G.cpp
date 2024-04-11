#include <cstdio>
#include <cstring>
#include <iostream>
#define MN 1010000

int b[MN], id[MN], tot = 0, id2[MN];
int n, m;
int d[MN], d2[MN];
int h[MN], nxt[2 * MN], to[2 * MN], K = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

int dfs(int x)
{
	if(b[x] != -1) return b[x];
	if(d[x] == 0) b[x] = (1 << id[x]);
	else b[x] = 0;
	for(int i = h[x]; i; i = nxt[i])
		dfs(to[i]), b[x] |= b[to[i]];
	return b[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v); d[u]++; d2[v]++;
	}
	memset(b, -1, sizeof(b));
	for(int i = 1; i <= n; i++) if(d[i] == 0) id[i] = tot++;
	tot = 0;
	for(int i = 1; i <= n; i++) if(d2[i] == 0) id2[tot++] = i;
	for(int i = 1; i <= n; i++) dfs(i);
	for(int S = 1; S < (1 << tot) - 1; S++)
	{
		int T = 0;
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < tot; i++)
			if((S >> i) & 1) T |= b[id2[i]], cnt1++;
		for(int i = 0; i < tot; i++)
			if((T >> i) & 1) cnt2++;
		if(cnt1 == cnt2) {puts("NO"); return 0;}
	}
	puts("YES");
}