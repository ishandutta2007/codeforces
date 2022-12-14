#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 1005, INF = 500000000;
const int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
typedef pair <int, int> pii;
#define fi first
#define se second

char g[MAXN][MAXN];
int dist[4][MAXN][MAXN], n, m;
queue <pii> q;

inline bool inmap(pii x){return x.fi >= 1 && x.fi <= n && x.se >= 1 && x.se <= m;}
void bfs(int x){
	int i, j; pii now;
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= m; ++ j)
			if(g[i][j] == x + '0'){
				q.push(pii(i, j));
				dist[x][i][j] = 0;
			}else dist[x][i][j] = INF;
	while(!q.empty()){
		now = q.front(); q.pop();
		for(i = 0; i < 4; ++ i){
			now.fi += dx[i], now.se += dy[i];
			if(inmap(now) && g[now.fi][now.se] != '#' && dist[x][now.fi][now.se] == INF){
				dist[x][now.fi][now.se] = dist[x][now.fi - dx[i]][now.se - dy[i]] + (g[now.fi][now.se] == '.' ? 1 : 0);
				q.push(now);
			}
			now.fi -= dx[i], now.se -= dy[i];
		}
	}
}
int main(){
	int i, j, k, t1, t2, a, b, ans = INF;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i) scanf("%s", g[i] + 1);
	for(i = 1; i <= 3; ++ i) bfs(i);
	for(i = 1; i <= 3; ++ i){
		for(a = 1; a == i; ++ a) ;
		for(b = a + 1; b == i; ++ b) ;
		t1 = INF; t2 = 0;
		for(j = 1; j <= n; ++ j)
			for(k = 1; k <= m; ++ k)
				if(g[j][k] == a + '0' && dist[i][j][k] < t1) t1 = dist[i][j][k];
		t2 += t1; t1 = INF;
		for(j = 1; j <= n; ++ j)
			for(k = 1; k <= m; ++ k)
				if(g[j][k] == b + '0' && dist[i][j][k] < t1) t1 = dist[i][j][k];
		if(ans > t1 + t2) ans = t1 + t2;
	}
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= m; ++ j)
			if(g[i][j] == '.') ans = min(ans, dist[1][i][j] + dist[2][i][j] + dist[3][i][j] - 2);
	printf("%d\n", ans == INF ? -1 : ans);
	return 0;
}