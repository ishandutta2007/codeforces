#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 405, INF = 0x3f3f3f3f;

int n, m;
bool g[MAXN][MAXN], vis[MAXN];
queue <int> q;

int bfs(bool flag){
	int i, now, size, step = 0;
	memset(vis, false, sizeof(vis));
	while(!q.empty()) q.pop();
	vis[1] = true; q.push(1);
	while(!q.empty()){
		size = q.size();
		++ step;
		while(size --){
			now = q.front(); q.pop();
			for(i = 1; i <= n; ++ i)
				if(g[now][i] == flag && !vis[i]){
					vis[i] = true;
					q.push(i);
					if(i == n) return step;
				}
		}
	}
	return INF;
}
int main(){
	int i, u, v, ans;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = true;
	} ans = max(1, max(bfs(true), bfs(false)));
	printf("%d\n", ans == INF ? -1 : ans);
	return 0;
}