#include <cstdio>
#include <iostream>
#define MN 1010000

bool vis[MN];
int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
int x[MN], y[MN];

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void dfs(int x)
{
	vis[x] = 1;
	for(int i = h[x]; i; i = nxt[i])
		if(!vis[to[i]]) dfs(to[i]);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n, m; scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) h[i] = 0, vis[i] = 0; K = 0;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
			ins(x[i], y[i]);
		}
		dfs(1); bool ok = 0;
		for(int i = 1; i <= n; i++) if(!vis[i]) {ok = 1; break;}
		if(ok)
		{
			int cnt1 = 0, cnt2 = 0;
			for(int i = 1; i <= n; i++) if(vis[i]) cnt1++; else cnt2++;
			puts("Yes");
			printf("%d %d\n", cnt1, cnt2);
			for(int i = 1; i <= n; i++) if(vis[i]) printf("%d ", i); puts("");
			for(int i = 1; i <= n; i++) if(!vis[i]) printf("%d ", i); puts("");
			continue;
		}
		
		for(int i = 1; i <= n; i++) h[i] = 0, vis[i] = 0; K = 0;
		for(int i = 1; i <= m; i++)	ins(y[i], x[i]);
		dfs(1); ok = 0;
		for(int i = 1; i <= n; i++) if(!vis[i]) {ok = 1; break;}
		if(ok)
		{
			int cnt1 = 0, cnt2 = 0;
			for(int i = 1; i <= n; i++) if(!vis[i]) cnt1++; else cnt2++;
			puts("Yes");
			printf("%d %d\n", cnt1, cnt2);
			for(int i = 1; i <= n; i++) if(!vis[i]) printf("%d ", i); puts("");
			for(int i = 1; i <= n; i++) if(vis[i]) printf("%d ", i); puts("");
			continue;
		}
		puts("No");
	}
}