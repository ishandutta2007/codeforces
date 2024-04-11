#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring> 
#include <queue>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;
const int N = 100030, L = 17, P = 23, M = N << 1;
int n, m, Q, f[N], fa[N][L], dep[N], c[N], tot = 0;
LL dis[N], d[P][N];
bool vis[N];
int head[N], numE = 0;
priority_queue<PLI, vector<PLI>, greater<PLI> > q;
vector<PII> g[N];
struct E{
	int next, u, v, w;
}e[M];
void add(int u, int v, int w) {
	e[++numE] = (E) { head[u], u, v, w };
	head[u] = numE;	
}
int get(int x) {
	return x == f[x] ? x : f[x] = get(f[x]);
}
void dfs(int u, int last) {
	dep[u] = dep[last] + 1;
	fa[u][0] = last;
	for (int i = 1; i < L && fa[u][i - 1]; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = 0; i < g[u].size(); i++) {
		PII v = g[u][i];
		if(v.first == last) continue;
		dis[v.first] = dis[u] + v.second; 
		dfs(v.first, u);
	}
}
int lca(int x, int y) {
	while(dep[x] < dep[y]) swap(x, y);
	for (int i = L - 1; ~i; i--)
		if(dep[x] - (1 << i) >= dep[y])
			x = fa[x][i];
	 if(x == y) return x;
	 for (int i = L - 1; ~i; i--)
	 	if(fa[x][i] != fa[y][i])
	 		x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
void dijkstra(int s, int o) {
	memset(vis, false, sizeof vis);
	d[o][s] = 0; q.push(make_pair(0, s));
	while(!q.empty()) {
		PLI u = q.top(); q.pop();
		if(vis[u.second]) continue;
		vis[u.second] = true;
		for (int i = head[u.second]; i; i = e[i].next) {
			int v = e[i].v;
			if(d[o][u.second] + e[i].w < d[o][v]) {
				d[o][v] = d[o][u.second] + e[i].w;
				q.push(make_pair(d[o][v], v));
			}
		}
	}
} 
int main(){
	memset(d, 0x3f, sizeof d);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w); add(v, u, w);
	}
	
	for (int i = 1; i <= numE; i += 2) {
		int u = e[i].u, v = e[i].v;
		u = get(u), v = get(v);
		if(u != v) {
			f[u] = v;
			u = e[i].u, v = e[i].v;
			//cout << u << " :: " << v << " "  <<endl;
			g[u].push_back(make_pair(v, e[i].w));
			g[v].push_back(make_pair(u, e[i].w));
		} else {
			c[++tot] = e[i].u;	
		}
	}
	dfs(1, 0);
	for (int i = 1; i <= tot; i++) {
		dijkstra(c[i], i);
	} 
	scanf("%d", &Q);
	while(Q--) {
		int u, v; scanf("%d%d", &u, &v);
		int p = lca(u, v);
		//cout << dis[u] << " " << dis[v] << " " << dis[p] << " " << p << endl;
		LL res = dis[u] + dis[v] - 2 * dis[p];
		for (int i = 1; i <= tot; i++)
			res = min(res, d[i][u] + d[i][v]);
		printf("%lld\n", res);
	}
	return 0;
}