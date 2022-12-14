#include <cstdio>
#include <cstring>
#define MAXN 2005

struct edge{
	int n, p, w;
	void var(int _n, int _p, int _w){
		n = _n, p = _p, w = _w;
	}
}edges[MAXN << 1];
bool vis[MAXN];
int input[MAXN][MAXN], n, graph[MAXN][MAXN], dist[MAXN], partner[MAXN], g[MAXN], edgeSize;

void addEdge(int f, int t, int w){
	edges[++ edgeSize].var(t, g[f], w);
	g[f] = edgeSize;
	edges[++ edgeSize].var(f, g[t], w);
	g[t] = edgeSize;
}
void dfs(int fa_, int fa, int now, int d){
	graph[fa_][now] = d;
	for(int p = g[now]; p; p = edges[p].p)
		if(edges[p].n != fa) dfs(fa_, now, edges[p].n, d + edges[p].w);
}
int main(){
	int i, j, minPos, minDist;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= n; ++ j)
			scanf("%d", &input[i][j]);
	for(i = 1; i <= n; ++ i){
		if(input[i][i]){
			printf("NO\n");
			return 0;
		}
		for(j = i + 1; j <= n; ++ j)
			if(input[i][j] != input[j][i]){
				printf("NO\n");
				return 0;
			}
	}
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;
	for(i = 1; i <= n; ++ i){
		minDist = 1 << 30;
		for(j = 1; j <= n; ++ j)
			if(!vis[j] && dist[j] < minDist){
				minDist = dist[j];
				minPos = j;
			}
		if(!dist[minPos] && minPos != 1){
			printf("NO\n");
			return 0;
		}
		vis[minPos] = true;
		if(minPos != 1) addEdge(minPos, partner[minPos], dist[minPos]);
		for(j = 1; j <= n; ++ j)
			if(!vis[j] && dist[j] > input[minPos][j]){
				dist[j] = input[minPos][j];
				partner[j] = minPos;
			}
	}
	for(i = 1; i <= n; ++ i)
		dfs(i, -1, i, 0);
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= n; ++ j)
			if(input[i][j] != graph[i][j]){
				printf("NO\n");
				return 0;
			}
	printf("YES\n");
	return 0;
}