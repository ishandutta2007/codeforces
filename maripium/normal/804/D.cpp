#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, q;
vector<int> g[N];
int comp[N], root;
int down[N], up[N];
vector<int> vals[N];
vector<long long> suf[N];
map<int,long long> f[N];

void dfs_down(int u,int p) {
	comp[u] = root;
	for (int v : g[u]) if (v != p) {
		dfs_down(v, u), down[u] = max(down[u], down[v] + 1);
	}
}

void dfs_up(int u,int p) {
	vals[root].push_back(max(down[u], up[u]));
	int mx0, mx1; mx0 = mx1 = -1e9;
	for (int v : g[u]) if (v != p) {
		if (down[v] > mx0) mx1 = mx0, mx0 = down[v];
		else if (down[v] > mx1) mx1 = down[v];
	}
	for (int v : g[u]) if (v != p) {
		up[v] = up[u] + 1;
		if (down[v] == mx0) up[v] = max(up[v], mx1 + 2);
		else up[v] = max(up[v], mx0 + 2);
		dfs_up(v, u);
	}
}

void calc(int u) {
	root = u;
	dfs_down(u, -1), dfs_up(u, -1);
	sort(vals[u].begin(), vals[u].end());
	suf[u].resize(vals[u].size());
	for (int i = suf[u].size() - 1; i >= 0; --i) {
		suf[u][i] = vals[u][i];
		if (i + 1 < (int)suf[u].size()) suf[u][i] += suf[u][i + 1];
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= m; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	for (int u = 1; u <= n; ++u) if (comp[u] == 0) calc(u);
	while (q--) {
		int u, v; scanf("%d %d", &u, &v);
		u = comp[u], v = comp[v];
		if (u == v) {
			printf("-1\n"); continue;
		}
		long long pairs = 1LL * (int)vals[u].size() * (int)vals[v].size();
		if (f[u].count(v)) {
			printf("%.9lf\n", (double)f[u][v] / (double)pairs);
			continue;
		} 
		long long ans = 0;
		long long rem = pairs;
		if (vals[u].size() < vals[v].size()) swap(u, v);
		int mx = max(vals[u].back(), vals[v].back());
		for (int x : vals[v]) {
			int pos = upper_bound(vals[u].begin(), vals[u].end(), mx - x - 1) - vals[u].begin();
			if (pos == vals[u].size()) continue;
			int sub = vals[u].size() - pos;
			ans += 1LL * sub * (x + 1) + suf[u][pos], rem -= sub;
		}
		ans += rem * mx;
		f[u][v] = f[v][u] = ans;
		printf("%.9lf\n", (double)ans / (double)pairs);
	}
}