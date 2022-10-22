#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 3e5 + 10, P = 998244353;
int n, k;
int c[N], sz[N], col[N], vis[N];
int pa[N], dep[N], dfn[N], dfc = 0;
int dp[N][2];
vector<int> g[N], p[N];

void adde(int u, int v) { g[u].push_back(v); }

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	pa[u] = fa;
	dfn[u] = ++dfc;
	sz[u] = 1, col[u] = (c[u] == 0);
	for(int &v : g[u]) if(v != fa) dfs(v, u), sz[u] += sz[v], col[u] += col[v];
	return;
}

int LCA(int u, int v) {
	if(dep[u] > dep[v]) swap(u, v);
	for(; dep[u] < dep[v]; v = pa[v]);
	if(u == v) return u;
	for(; u != v; u = pa[u], v = pa[v]);
	return u;
}

void Visit(int u, int a) {
	int C = c[u];
	for(; !vis[u] && dep[u] >= dep[a]; u = pa[u]) vis[u] = C;
	if(dep[u] >= dep[a] && vis[u] != C) printf("0\n"), exit(0);
	return;
}

void DFS(int u, int fa) {
	if(vis[u]) {
		dp[u][1] = 1, dp[u][0] = 0;
		return;
	}
	vis[u] = k + 1;
	dp[u][0] = 1, dp[u][1] = 0;
	for(int &v : g[u]) {
		if(v == fa) continue;
		DFS(v, u);
		dp[u][1] = 1ll * (dp[v][0] + dp[v][1]) % P * dp[u][1] % P; 
		(dp[u][1] += 1ll * dp[u][0] * dp[v][1] % P) %= P;
		dp[u][0] = 1ll * (dp[v][0] + dp[v][1]) % P * dp[u][0] % P;
	}
	return;
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		p[c[i]].push_back(i);
	}
	for(int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		adde(u, v), adde(v, u);
	}
	dep[0] = -1;
	dfs(1, 0);
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 2; i <= n; i++) {
		if(sz[i] == col[i] || col[1] - col[i] == sz[1] - sz[i]) {
			if(sz[i] == col[i]) vis[i] = k + 1;
			else vis[pa[i]] = k + 1;
			continue;
		}
		adde(i, pa[i]), adde(pa[i], i);
	}
	for(int i = 1; i <= k; i++) {
		if(p[i].empty()) continue;
		sort(p[i].begin(), p[i].end(), [&] (int a, int b) {
			return dfn[a] < dfn[b];
		} );
		int ac = LCA(p[i].front(), p[i].back());
		for(int &v : p[i]) Visit(v, ac);
	}
	int ans = 1;
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		DFS(i, 0);
		ans = 1ll * dp[i][1] * ans % P;
	}
	printf("%d\n", ans);
	return 0;
}