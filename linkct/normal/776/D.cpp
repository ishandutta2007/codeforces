#include <cstdio>
const int MAXN = 100005, MAXM = 100005;

int n, m, u[MAXM], v[MAXM], g[MAXN], vis[MAXN], state[MAXM];
int nxt[MAXN << 1], to[MAXN << 1], edgeSize, dfsClock, col[MAXN];

void addEdge(int x, int y){
	nxt[++ edgeSize] = g[x];
	to[g[x] = edgeSize] = y;
}
bool dfs(int x, int c){
	if(vis[x] == dfsClock) return col[x] == c;
	vis[x] = dfsClock, col[x] = c;
	for(int p = g[x]; p; p = nxt[p])
		if(!dfs(to[p], c ^ state[p >> 1] ^ 1))
			return false;
	return true;
}
int main(){
	int i, e, cnt;
	scanf("%d%d", &m, &n);
	for(i = 1; i <= m; ++ i)
		scanf("%d", &state[i]);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &cnt);
		while(cnt --){
			scanf("%d", &e);
			if(u[e]) v[e] = i;
			else u[e] = i;
		}
	} edgeSize = 1;
	for(i = 1; i <= m; ++ i){
		addEdge(u[i], v[i]);
		addEdge(v[i], u[i]);
	}
	for(i = 1; i <= n; ++ i)
		if(!vis[i]){
			++ dfsClock;
			if(!dfs(i, 0)){
				++ dfsClock;
				if(!dfs(i, 1)){
					printf("NO\n");
					return 0;
				}
			}
		}
	printf("YES\n");
	return 0;
}