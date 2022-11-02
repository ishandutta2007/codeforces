#include <bits/stdc++.h>

using ll = long long;

const ll inf = 1e18;

const int maxn = 505 * 505;

ll f[maxn][22];
int n,m,k,w,hd[maxn],tl,G[505][505],sz;

struct edge {
	int v,w,nxt;
}E[maxn << 5];
void add(int u,int v,int w) { E[++tl].v=v;E[tl].w=w;E[tl].nxt=hd[u];hd[u]=tl;}
void add_edge(int u,int v,int w) { add(u,v,w); add(v,u,w); }

ll dfs(int u,int z) {
	if (z == 0) return 0;
	if (f[u][z] != -1) return f[u][z];
	f[u][z] = inf;
	for (int i = hd[u]; i; i = E[i].nxt) 
		for (int j = 2; j <= z; j += 2) 
			f[u][z] = std::min(f[u][z],dfs(E[i].v,z - j) + (ll) E[i].w * j);
	return f[u][z];
}

int main() {
	std::memset(f,-1,sizeof(f));
	scanf("%d%d%d",&n,&m,&k);
	int sz = 0;
	for (int i = 1; i <= n; ++ i)
	for (int j = 1; j <= m; ++ j)
		G[i][j] = ++sz;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m - 1; ++ j) {
			scanf("%d",&w);
			add_edge(G[i][j],G[i][j+1],w);
		} 
	} 
	for (int i = 1; i < n; ++ i)
	for (int j = 1; j <= m; ++ j) {
		scanf("%d",&w);
		add_edge(G[i][j],G[i+1][j],w);
	}
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			if (k % 2) { printf("-1 "); }
			else printf("%d ",dfs(G[i][j],k));
		} puts("");
	} 
	return 0;
}