#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Arr = array<array<ll, 2>, 2>;
const int N = 300300;
const ll inf = 1e18;

ll d[N];
vector<tuple<int, ll, ll>> g[N];
int dep[N];
int par[20][N];
Arr go[20][N];

Arr mrg(Arr x, Arr y) {
	Arr z;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			z[i][j] = 1e18;
			for (int k = 0; k < 2; ++k) {
				z[i][j] = min(z[i][j], x[i][k] + y[k][j]);
			}
		}
	}
	return z;
}

void dfs(int u) {
	for (int i = 1; i < 20; ++i) {
		par[i][u] = par[i - 1][par[i - 1][u]];
		go[i][u] = mrg(go[i - 1][u], go[i - 1][par[i - 1][u]]);
	}
	for (auto e : g[u]) {
		int v; ll w0, w1;
		tie(v, w0, w1) = e;
		if (v != par[0][u]) {
			dep[v] = dep[u] + 1;
			par[0][v] = u;
			go[0][v][0][0] = min(w0, d[u] + d[v] + w1);
			go[0][v][0][1] = min(w0 + d[u], d[v] + w1);
			go[0][v][1][0] = min(w1 + d[u], d[v] + w0);
			go[0][v][1][1] = min(w1, d[u] + d[v] + w0);
			dfs(v);
		}
	}
}

int lca(int u,int v) {
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	for (int i = 19; i >= 0; --i) {
		if (dep[par[i][v]] >= dep[u]) {
			v = par[i][v];
		}
	}
	if (u == v) return u;
	for (int i = 19; i >= 0; --i) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][u];
}

Arr up(int u,int l) {
	Arr ans = Arr();
	ans[0][1] = ans[1][0] = d[u];
	for (int i = 0; i < 20; ++i) {
		if (l & (1 << i)) {
			ans = mrg(ans, go[i][u]);
			u = par[i][u];
		}
	}
	return ans;
}

Arr get(int u,int v) {
	int a = lca(u, v);
	auto l = up(u, dep[u] - dep[a]);
	auto r = up(v, dep[v] - dep[a]);
	swap(r[0][1], r[1][0]);
	return mrg(l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> d[i];
	for (int i = 0; i < n - 1; ++i) {
		int u, v; ll w0, w1;
		cin >> u >> v >> w0 >> w1;
		--u, --v;
		g[u].push_back(make_tuple(v, w0, w1));
		g[v].push_back(make_tuple(u, w0, w1));
	}
	{
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
		for (int i = 0; i < n; ++i) {
			q.push({d[i], i});
		}
		while (!q.empty()) {
			auto nw = q.top(); q.pop();
			int u = nw.second;
			if (nw.first != d[u]) {
				continue;
			}
			for (auto e : g[u]) {
				int v; ll w0, w1;
				tie(v, w0, w1) = e;
				if (d[v] > d[u] + w0 + w1) {
					d[v] = d[u] + w0 + w1;
					q.push({d[v], v});
				}
			}
		}
	}
	par[0][0] = 0;
	dfs(0);
	int q;
	cin >> q;
	while (q--) {
		int u, v; 
		cin >> u >> v;
		--u, --v;
		cout << get(u >> 1, v >> 1)[u & 1][v & 1] << '\n';
	}
}