#include<bits/stdc++.h>
 
using namespace std;
 
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
 
typedef pair<int, int> P;
typedef long long LL;
typedef double db;
const int N = 400 + 10, md = 998244353;
int n, m, dis[N];
int deg[N], flag = 0;
vector<vector<int> > g[2][N];
vector<int> e[N];
int ans[N][N], vis[N];
void bfs(int s) {
	static queue<int> q;
	q.push(s);
	rep(i, 0, n - 1) dis[i] = N;
	dis[s] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		rep(i, 0, SZ(e[u]) - 1) {
			int v = e[u][i];
			if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	rep(u, 0, n - 1) deg[u] = 0;
	g[0][s].resize(n), g[1][s].resize(n);
	rep(u, 0, n - 1) {
		rep(i, 0, SZ(e[u]) - 1) {
			int v = e[u][i];
			if(dis[v] == dis[u] + 1) g[0][s][u].push_back(v), deg[v]++, g[1][s][v].push_back(u);
		}
	}
	rep(u, 0, n - 1) rep(i, 0, 1) sort(ALL(g[i][s][u]));
	int prod = 1;
	rep(u, 0, n - 1) if(u != s) prod = 1ll * prod * deg[u] % md;
	ans[s][s] = prod;
	return;
}
 
int dfs(int u, int fa, int y) {
	if(u == y) return vis[u] = 1, 1;
	if(vis[u]) return vis[u] > 0;
	rep(i, 0, SZ(e[u]) - 1) {
		int v = e[u][i];
		if(v == fa) continue;
		if(dfs(v, u, y)) return vis[u] = 1, 1;
	}
	vis[u] = -1;
	return 0;
}
 
int f(int x, int y) {
	rep(u, 0, n - 1) deg[u] = vis[u] = 0, e[u].clear();
	rep(u, 0, n - 1) {
		int p = 0, sz = SZ(g[0][y][u]);
		rep(i, 0, SZ(g[0][x][u]) - 1) {
			int v = g[0][x][u][i];
			while(p < sz && g[0][y][u][p] < v) p++;
			if(p < sz && g[0][y][u][p] == v) deg[v]++;
		}
		p = 0, sz = SZ(g[1][y][u]);
		rep(i, 0, SZ(g[0][x][u]) - 1) {
			int v = g[0][x][u][i];
			while(p < sz && g[1][y][u][p] < v) p++;
			if(p < sz && g[1][y][u][p] == v) e[u].push_back(v);
		}
	}
	dfs(x, -1, y);
	int prod = 1;
	rep(u, 0, n - 1) if(vis[u] <= 0) prod = 1ll * prod * deg[u] % md;
	return prod;
}
 
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v), u--, v--;
		e[u].push_back(v), e[v].push_back(u);
	}
	rep(u, 0, n - 1) bfs(u);
	rep(x, 0, n - 1) rep(y, x + 1, n - 1) ans[x][y] = ans[y][x] = f(x, y);
	rep(x, 0, n - 1) {
		rep(y, 0, n - 1) printf("%d ", ans[x][y]);
		printf("\n");
	}
	return 0;
}