#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void add(int &x,int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
}

int mul(int x,int y) {
	return (long long) x * y % mod;
}

const int N = 100005;

int n, q;
vector<int> g[N];
vector<int> g2[N];
int le[N], ri[N], tot;
int dep[N], par[17][N];
set<int> ss;
vector<int> buf;
vector<int> ver;
int f[N][305];

void dfs(int u,int p) {
	le[u] = ++tot;
	for (int i = 1; i < 17; ++i) {
		par[i][u] = par[i - 1][par[i - 1][u]];
	} 
	for (int v : g[u]) {
		if (v == p) {
			continue;
		}
		dep[v] = dep[u] + 1;
		par[0][v] = u;
		dfs(v, u);
	}
	ri[u] = tot;
}

int lca(int u,int v) {
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	for (int i = 16; i >= 0; --i) {
		if (dep[par[i][v]] >= dep[u]) {
			v = par[i][v];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = 16; i >= 0; --i) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][u];
}

void dfs2(int u,int p,int up) {
	if (ss.find(u) != ss.end()) {
		buf.push_back(up);
	}
	for (int v : g2[u]) {
		if (v == p) {
			continue;
		}
		dfs2(v, u, up + (ss.find(u) != ss.end()));
	}
}

void solve() {
	int k, m, r;
	scanf("%d %d %d", &k, &m, &r);
	ss.clear();
	ver.clear();
	ver.push_back(r);
	for (int i = 1; i <= k; ++i) {
		int u;
		scanf("%d", &u);
		ver.push_back(u);
		ss.insert(u);
	} 
	sort(ver.begin(), ver.end(), [&](int u,int v) {
		return le[u] < le[v];
	});
	assert(ver.size() == k + 1);
	for (int i = 1; i <= k; ++i) {
		ver.push_back(lca(ver[i], ver[i - 1]));
	}
	sort(ver.begin(), ver.end(), [&](int u,int v) {
		return le[u] < le[v];
	});
	ver.resize(unique(ver.begin(), ver.end()) - ver.begin());
	stack<int> st;
	for (int v : ver) {
		g2[v].clear();
	}
	for (int v : ver) {
		while (st.size() && ri[st.top()] < ri[v]) {
			st.pop();
		}
		if (st.size()) {
			g2[st.top()].push_back(v);
			g2[v].push_back(st.top());
		}
		st.push(v);
	}
	buf.clear();
	dfs2(r, -1, 0);
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= m; ++j) {
			f[i][j] = 0;
		}
	}
	f[0][0] = 1;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (j < m) {
				add(f[i + 1][j + 1], f[i][j]);
			} 
			if (j > buf[i]) {
				add(f[i + 1][j], mul(j - buf[i], f[i][j]));
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		add(ans, f[k][i]);
	}
	printf("%d\n", ans);
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 2; i <= n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	par[0][1] = 1;
	dfs(1, -1);
	while (q--) {
		solve();
	}
}