#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 10005, MAXM = 2005, INF = 0x3f3f3f3f;

struct dinic{
	struct edge{
		int n, p, r;
		void var(int _n, int _p, int _r){
			n = _n, p = _p, r = _r;
		}
	}edges[(MAXM * 11 + MAXN) << 1];
	int g[MAXN + MAXM], s, t, cur[MAXN + MAXM], d[MAXN + MAXM], edgeSize;
	void init(int _s, int _t){
		memset(g, 0, sizeof(g));
		edgeSize = 1;
		s = _s, t = _t;
	}
	void addEdge(int f, int t, int c){
		edges[++ edgeSize].var(t, g[f], c);
		g[f] = edgeSize;
		edges[++ edgeSize].var(f, g[t], 0);
		g[t] = edgeSize;
	}
	bool bfs(){
		int p, v, now;
		memset(d, 0, sizeof(d));
		queue <int> q;
		q.push(s);
		d[s] = 1;
		while(!q.empty()){
			now = q.front();
			q.pop();
			for(p = g[now]; p; p = edges[p].p){
				v = edges[p].n;
				if(!d[v] && edges[p].r){
					d[v] = d[now] + 1;
					q.push(v);
				}
			}
		}
		return d[t];
	}
	int dfs(int x, int a){
		if(x == t || !a) return a;
		int flow = 0, f;
		for(int& p = cur[x]; p; p = edges[p].p){
			edge& e = edges[p];
			if(d[e.n] == d[x] + 1 && (f = dfs(e.n, min(e.r, a))) > 0){
				e.r -= f;
				edges[p ^ 1].r += f;
				flow += f;
				a -= f;
				if(!a) break;
			}
		}
		return flow;
	}
	int maxFlow(){
		int flow = 0, i;
		while(bfs()){
			for(i = s; i <= t; ++ i)
				cur[i] = g[i];
			flow += dfs(s, INF);
		}
		return flow;
	}
}maxf;
int n, m, g, gender[MAXN], cost[MAXN], reqg[MAXM], prof[MAXM], req[MAXM][12], fri[MAXM], sumg;

int main(){
	int i, j;
	scanf("%d%d%d", &n, &m, &g);
	maxf.init(0, n + m + 1);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &gender[i]);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &cost[i]);
		if(gender[i]) maxf.addEdge(0, i, cost[i]);
		else maxf.addEdge(i, n + m + 1, cost[i]);
	}
	for(i = 1; i <= m; ++ i){
		scanf("%d%d%d", &reqg[i], &prof[i], &req[i][0]);
		for(j = 1; j <= req[i][0]; ++ j){
			scanf("%d", &req[i][j]);
			if(reqg[i]) maxf.addEdge(n + i, req[i][j], INF);
			else maxf.addEdge(req[i][j], n + i, INF);
		}
		scanf("%d", &fri[i]);
		if(fri[i]) prof[i] += g, sumg += g;
		prof[0] += prof[i];
		if(reqg[i]) maxf.addEdge(0, n + i, prof[i]);
		else maxf.addEdge(n + i, n + m + 1, prof[i]);
	}
	printf("%d\n", prof[0] - sumg - maxf.maxFlow());
	return 0;
}
/*
5 5 9
0 1 1 1 0
1 8 6 2 3
0 7 3 3 2 1 1
1 8 1 5 1
1 0 3 2 1 4 1
0 8 3 4 2 1 0
1 7 2 4 1 1
ans = 2

5 5 8
1 0 1 1 1
6 5 4 2 8
0 6 3 2 3 4 0
0 8 3 3 2 4 0
0 0 3 3 4 1 1
0 10 3 4 3 1 1
0 4 3 3 4 1 1
ans = 16

1 1 0
1
1
1 0 1 1 0
*/