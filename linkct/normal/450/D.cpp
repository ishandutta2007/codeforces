#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 1 << 29, MAXN = 100005, MAXM = 400005;
typedef pair <int, int> pii;

struct edge{
	int n, p, w;
	bool isTR, isC;
	edge(){isTR = isC = false;}

	void var(int _n, int _p, int _w, bool isTR_){
		n = _n, p = _p, w = _w, isTR = isTR_;
	}
}edges[MAXM << 1];
int n, m, k, g[MAXN], edgeSize, dist[MAXN], id[MAXN];
bool vis[MAXN];

void dijkstra(){
	pii temp;
	int i, j, minDist, minPos, v;
	priority_queue <pii, vector <pii>, greater<pii> > q;
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;
	for(i = 1; i <= n; ++ i) q.push(pii(dist[i], i));
	for(i = 1; i <= n; ++ i){
		do{
			temp = q.top();
			q.pop();
		}while(vis[temp.second] || temp.first != dist[temp.second]);
		vis[temp.second] = true;
		//printf("%d %d\n", temp.second, temp.first);
		for(j = g[temp.second]; j; j = edges[j].p){
			v = edges[j].n;
			if(!vis[v] && dist[v] > dist[temp.second] + edges[j].w){
				dist[v] = dist[temp.second] + edges[j].w;
				q.push(pii (dist[v], v));
			}
		}
	}
}
void addEdge(int f, int t, int w, bool isTR, bool mode){
	edges[++ edgeSize].var(t, g[f], w, isTR);
	g[f] = edgeSize;
	if(mode){
		edges[++ edgeSize].var(f, g[t], w, isTR);
		g[t] = edgeSize;
	}
}
int main(){
	int i, f, w, t, ans = 0, p;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d%d", &f, &t, &w);
		addEdge(f, t, w, false, true);
	}
	for(i = 1; i <= k; ++ i){
		scanf("%d%d", &t, &w);
		addEdge(1, t, w, true, false);
	}
	dijkstra();
	for(i = 1; i <= n; ++ i)
		for(p = g[i]; p; p = edges[p].p)
			if(dist[i] + edges[p].w == dist[edges[p].n]){
				edges[p].isC = true;
				id[edges[p].n] ++;
			}
	for(i = edgeSize; i && edges[i].isTR; -- i)
		if(!edges[i].isC)
			ans ++;
		else if(id[edges[i].n] > 1){
			id[edges[i].n] --;
			ans ++;
		}
	printf("%d\n", ans);
	return 0;
}