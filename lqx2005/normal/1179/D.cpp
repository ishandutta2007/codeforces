#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<i64, int>
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 5e5 + 10;
int n, used[N];
vector<int> g[N];
int siz[N], sze[N], sz[N], fa[N], mx[N];
i64 dp[N], x[N], y[N], mn[N];
int q[N];
i64 ans = LLONG_MAX;

int ask(int u, int v) {
	if(fa[u] == v) return sze[u];
	return n - sze[v];
}

void dfs1(int u, int fa, int &c, int all) {
	siz[u] = 1;
	mx[u] = 0;
	for(int v : g[u]) {
		if(v == fa || used[v]) continue;
		dfs1(v, u, c, all);
		siz[u] += siz[v];
		mx[u] = max(mx[u], siz[v]);
	}
	mx[u] = max(mx[u], all - siz[u]);
	if(c == -1 || mx[c] > mx[u]) c = u;
	return;
}

void dfs2(int u, int fa) {
	siz[u] = 1;
	sz[u] = ask(u, fa);
	mn[u] = 1ll * sz[u] * sz[u];
	for(int v : g[u]) {
		if(v == fa || used[v]) continue;
		dfs2(v, u);
		siz[u] += siz[v];
	}
	for(int v : g[u]) {
		if(v == fa || used[v]) continue;
		mn[u] = min(mn[u], mn[v] + 1ll * (sz[u] - sz[v]) * (sz[u] - sz[v]));
	}
	return;
}

void divide(int u, int all) {
	int c = -1;
	dfs1(u, 0, c, all);
	u = c;
	vector<int> son;
	for(int v : g[u]) {
		if(used[v]) continue;
		dfs2(v, u);
		y[v] = mn[v] + 1ll * sz[v] * sz[v] - 2ll * n * sz[v];
		x[v] = sz[v];
		son.push_back(v);
		ans = min(ans, mn[v] + 1ll * (n - sz[v]) * (n - sz[v]));
	}
	sort(son.begin(), son.end(), [&](int a, int b) {
		if(x[a] != x[b]) return x[a] > x[b];
		return y[a] > y[b];
	});
	int l = 1, r = 0;
	for(int i : son) {
		while(l < r && (y[q[l + 1]] - y[q[l]]) >= - 2 * x[i] * (x[q[l + 1]] - x[q[l]])) l++;
		int j = q[l];
		if(l <= r) ans = min(ans, y[i] + y[j] + 2 * x[i] * x[j] + 1ll * n * n);
		while(l <= r && x[q[r]] == x[i]) r--;
		while(l < r && (x[q[r]] - x[i]) * (y[q[r - 1]] - y[i]) - (x[q[r - 1]] - x[i]) * (y[q[r]] - y[i]) <= 0) r--;
		q[++r] = i;
	}
	used[u] = 1;
	for(int v : g[u]) {
		if(used[v]) continue;
		divide(v, siz[v]);
	}
	return;
}

void dfs(int u, int fa) {
	::fa[u] = fa;
	sze[u] = 1;
	for(int v : g[u]) {
		if(v == fa) continue;
		dfs(v, u);
		sze[u] += sze[v];
	}
	return;
}

int main() {
	scanf("%d", &n);
	for(int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	divide(1, n);
	printf("%lld\n", 1ll * n * (n - 1) / 2 + (1ll * n * n - ans) / 2);
	return 0;
}