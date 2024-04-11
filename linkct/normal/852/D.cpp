#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXV = 605, MAXP = 205, MAXN = MAXV + MAXP, MAXM = MAXV * MAXP, INF = 0x3f3f3f3f;

struct Dinic{
	struct Edge{
		int n, p, r;
		void var(int a, int b, int c){
			n = a, p = b, r = c;
		}
	}edges[MAXM << 1];
	int g[MAXN], cur[MAXN], d[MAXN], s, t, edgeSize;
	queue <int> q;
	void addEdge(int u, int v, int w){
		edges[++ edgeSize].var(v, g[u], w);
		g[u] = edgeSize;
		edges[++ edgeSize].var(u, g[v], 0);
		g[v] = edgeSize;
	}
	void init(int s_, int t_){
		memset(g, 0, sizeof(g));
		edgeSize = 1;
		s = s_, t = t_;
	}
	bool bfs(){
		int now, p;
		memset(d, 0, sizeof(d));
		q.push(s), d[s] = 1;
		while(!q.empty()){
			now = q.front(); q.pop();
			cur[now] = g[now];
			for(p = g[now]; p; p = edges[p].p)
				if((!d[edges[p].n]) && edges[p].r){
					d[edges[p].n] = d[now] + 1;
					q.push(edges[p].n);
				}
		} return d[t];
	}
	int dfs(int x, int a){
		if(x == t || !a) return a;
		int f, flow = 0;
		for(int &p = cur[x]; p; p = edges[p].p)
			if(d[edges[p].n] == d[x] + 1 && (f = dfs(edges[p].n, min(edges[p].r, a)))){
				flow += f, edges[p ^ 1].r += f;
				edges[p].r -= f; if(!(a -= f)) break;
			}
		return flow;
	}
	int solve(){
		int ret = 0;
		while(bfs()) ret += dfs(s, INF);
		return ret;
	}
}maxFlow;
int n, m, p, c, pos[MAXP], g[MAXV][MAXV];

inline void update(int &a, int b){if(a > b) a = b;}
bool check(int mx){
	int i, j;
	maxFlow.init(0, n + p + 1);
	for(i = 1; i <= p; ++ i){
		maxFlow.addEdge(0, i, 1);
		for(j = 1; j <= n; ++ j)
			if(g[pos[i]][j] <= mx)
				maxFlow.addEdge(i, p + j, 1);
	}
	for(i = 1; i <= n; ++ i)
		maxFlow.addEdge(p + i, p + n + 1, 1);
	return maxFlow.solve() >= c;
}
int main(){
	int i, j, k, u, v, w, l, r, mid;
	scanf("%d%d%d%d", &n, &m, &p, &c);
	for(i = 1; i <= p; ++ i)
		scanf("%d", &pos[i]);
	memset(g, 0x3f, sizeof(g));
	for(i = 1; i <= m; ++ i){
		scanf("%d%d%d", &u, &v, &w);
		if(w < g[u][v]) g[u][v] = g[v][u] = w;
	}
	for(i = 1; i <= n; ++ i) g[i][i] = 0;
	for(k = 1; k <= n; ++ k)
		for(i = 1; i <= n; ++ i)
			for(j = 1; j <= n; ++ j)
				update(g[i][j], g[i][k] + g[k][j]);
	l = 0, r = 1731311;
	while(l < r){
		mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	} if(check(r)) printf("%d\n", r);
	else printf("-1\n");
	return 0;
}