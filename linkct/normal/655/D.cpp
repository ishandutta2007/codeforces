#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 100005, MAXM = 100005;

int n, m, g[MAXN], u[MAXM], v[MAXM], nxt[MAXM], to[MAXM];
int edgeSize, deg[MAXN], dp[MAXN];
bool vis[MAXN]; queue <int> q;

void addEdge(int x, int y){
	nxt[++ edgeSize] = g[x];
	to[g[x] = edgeSize] = y;
	++ deg[y];
}
bool check(int x){
	int i, now, p;
	memset(g, 0, sizeof(g));
	memset(deg, 0, sizeof(deg));
	edgeSize = 0;
	for(i = 1; i <= x; ++ i)
		addEdge(v[i], u[i]);
	while(!q.empty()) q.pop();
	for(i = 1; i <= n; ++ i)
		if(!deg[i]){
			q.push(i);
			if(int(q.size()) > 1) return false;
		}
	memset(dp, 0, sizeof(dp));
	dp[q.front()] = 1;
	while(!q.empty()){
		now = q.front(); q.pop();
		for(p = g[now]; p; p = nxt[p]){
			dp[to[p]] = max(dp[to[p]], dp[now] + 1);
			if(!(-- deg[to[p]])) q.push(to[p]);
		}
	}
	memset(vis, false, sizeof(vis));
	for(i = 1; i <= n; ++ i){
		if(vis[dp[i]]) return false;
		vis[dp[i]] = true;
	}
	return true;
}
int main(){
	int i, l, r, mid;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= m; ++ i)
		scanf("%d%d", &u[i], &v[i]);
	l = 1, r = m;
	while(l < r){
		mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(!check(r)) printf("-1\n");
	else printf("%d\n", r);
	return 0;
}