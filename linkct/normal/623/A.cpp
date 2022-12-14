#include <cstdio>
const int MAXN = 505;

int n, m, vis[MAXN], deg[MAXN];
bool g[MAXN][MAXN];

bool dfs(int x, int col){
	if(vis[x]) return vis[x] == col;
	vis[x] = col;
	for(int i = 1; i <= n; ++ i)
		if(i != x && !g[x][i] && !dfs(i, - col)) return false;
	return true;
}
int main(){
	int i, j, u, v;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = true;
	}
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= n; ++ j)
			if(i != j && !g[i][j])
				++ deg[i], ++ deg[j];
	for(i = 1; i <= n; ++ i){
		if(vis[i] || !deg[i]) continue;
		if(!dfs(i, 1)){
			printf("No\n");
			return 0;
		}
	}
	for(i = 1; i <= n; ++ i){
		if(!vis[i]) continue;
		for(j = 1; j <= n; ++ j)
			if(vis[j] == - vis[i] && g[i][j]){
				printf("No\n");
				return 0;
			}
	}
	printf("Yes\n");
	for(i = 1; i <= n; ++ i)
		if(vis[i] == -1) putchar('a');
		else if(vis[i] == 0) putchar('b');
		else putchar('c');
	putchar('\n');
	return 0;
}