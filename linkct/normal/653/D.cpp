#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 55, MAXM = 505, INF = 0x3f3f3f3f;
const double eps = 1e-9;

struct Dinic{
	struct edge{
		int n, p, r;
		void var(int n_, int p_, int r_){
			n = n_, p = p_, r = r_;
		}
	}edges[MAXM << 1];
	int g[MAXN], edgeSize, s, t, d[MAXN], cur[MAXN];
	queue <int> q;
	
	void init(int s_, int t_){
		memset(g, 0, sizeof(g));
		edgeSize = 1; s = s_, t = t_;
	}
	void addEdge(int u, int v, int r){
		edges[++ edgeSize].var(v, g[u], r);
		g[u] = edgeSize;
		edges[++ edgeSize].var(u, g[v], 0);
		g[v] = edgeSize;
	}
	bool bfs(){
		int now, p;
		memset(d, 0, sizeof(d));
		d[s] = 1; q.push(s);
		while(!q.empty()){
			now = q.front(); q.pop(); cur[now] = g[now];
			for(p = g[now]; p; p = edges[p].p)
				if(edges[p].r && !d[edges[p].n]){
					d[edges[p].n] = d[now] + 1;
					q.push(edges[p].n);
				}
		}
		return d[t];
	}
	int dfs(int x, int a){
		if(x == t || !a) return a;
		int f, flow = 0;
		for(int &p = cur[x]; p; p = edges[p].p)
			if(d[edges[p].n] == d[x] + 1 && (f = dfs(edges[p].n, min(a, edges[p].r)))){
				flow += f; edges[p ^ 1].r += f;
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
int n, m, x, u[MAXM], v[MAXM], w[MAXM];

bool check(double limit){
	maxFlow.init(1, n);
	for(int i = 1; i <= m; ++ i)
		maxFlow.addEdge(u[i], v[i], int(w[i] / limit + eps));
	return maxFlow.solve() >= x;
}
int main(){
	int i, maxv = 0, minv = INF; double l, r, mid;
	scanf("%d%d%d", &n, &m, &x);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		if(w[i] > maxv) maxv = w[i];
		if(w[i] < minv) minv = w[i];
	}
	l = double(minv) / x, r = maxv;
	for(i = 1; i <= 60; ++ i){
		mid = (l + r) / 2.0;
		if(check(mid)) l = mid;
		else r = mid;
	}
	printf("%.10f\n", r * x);
	return 0;
}