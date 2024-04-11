#include <iostream>
#include <algorithm>
#include <cstdio>
#define MN 2210000

int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
int low[MN], dfn[MN], D = 0, inq[MN], st[MN], top = 0, id[MN], tot = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void tarjan(int x)
{
	low[x] = dfn[x] = ++D; inq[x] = 1; st[++top] = x;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(!dfn[to[i]])
		{
			tarjan(to[i]);
			low[x] = std::min(low[x], low[to[i]]);
		}
		else if(inq[to[i]]) low[x] = std::min(low[x], dfn[to[i]]);
	}
	if(low[x] == dfn[x])
	{
		++tot;
		do {
			id[st[top]] = tot; 
			inq[st[top]] = 0;
		} while(st[top--] != x);
	}
}

int b[MN], l[MN], r[MN];

int main()
{
	int t, T, n, m; scanf("%d%d%d%d", &t, &T, &n, &m);
	int N = 0; b[++N] = 0; b[++N] = t;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		b[++N] = l[i]; b[++N] = r[i]; if(t - l[i] >= 0) b[++N] = t - l[i]; if(t - r[i] >= 0) b[++N] = t - r[i];
	}
	std::sort(b + 1, b + N + 1); N = std::unique(b + 1, b + N + 1) - b - 1;
	while(b[N] > T) N--;
	for(int i = 1; i < N; i++) ins(i, i + 1), ins(i + N + 1, i + N), ins(i + 2 * N, i + 2 * N + 1), ins(i + 3 * N + 1, i + 3 * N);
	ins(2 * N, N); ins(4 * N, 3 * N);
	for(int i = 1; i <= N; i++)
	{
		int p = std::upper_bound(b + 1, b + N + 1, t - b[i] - 1) - b - 1;
		if(p) ins(i, p + 3 * N), ins(p + 2 * N, i + N);
		if(i != N)
		{
			p = std::upper_bound(b + 1, b + N + 1, T - b[i + 1]) - b - 1;
			if(p) ins(i + N, p + 2 * N), ins(p + 3 * N, i);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int x = std::lower_bound(b + 1, b + N + 1, l[i]) - b - 1;
		int y = std::lower_bound(b + 1, b + N + 1, r[i]) - b;
		if(x) ins(i + 4 * N, x + N), ins(x, i + 4 * N + n);
		ins(i + 4 * N, y), ins(y + N, i + 4 * N + n);
		if(x) ins(i + 4 * N + n, x + 3 * N), ins(x + 2 * N, i + 4 * N);
		ins(i + 4 * N + n, y + 2 * N), ins(y + 3 * N, i + 4 * N);
	}
	for(int i = 1; i <= m; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		ins(a + 4 * N, b + 4 * N + n);
		ins(b + 4 * N, a + 4 * N + n);
		ins(a + 4 * N + n, b + 4 * N);
		ins(b + 4 * N + n, a + 4 * N);
	}
	for(int i = 1; i <= 4 * N + 2 * n; i++) if(!dfn[i]) tarjan(i);
	for(int i = 1; i <= N; i++) if(id[i] == id[i + N]) return 0 * puts("IMPOSSIBLE");
	for(int i = 2 * N + 1; i <= 3 * N; i++) if(id[i] == id[i + N]) return 0 * puts("IMPOSSIBLE");
	for(int i = 1; i <= n; i++) if(id[i + 4 * N] == id[i + 4 * N + n]) return 0 * puts("IMPOSSIBLE");
	puts("POSSIBLE");
	for(int i = 1; i <= N; i++) if(id[i] < id[i + N]) {printf("%d ", b[i]); break;}
	for(int i = 2 * N + 1; i <= 3 * N; i++) if(id[i] < id[i + N]) {printf("%d ", b[i - 2 * N]); break;}
	puts("");
	for(int i = 1; i <= n; i++) if(id[i + 4 * N] < id[i + 4 * N + n]) printf("1"); else printf("2");
}