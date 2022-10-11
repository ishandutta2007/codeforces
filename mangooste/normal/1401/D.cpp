#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<int mod>
struct modular {
	int val;

	modular(int x = 0) : val((x % mod + mod) % mod) {}

	modular operator * (modular m) {
		return (ll) val * m.val % mod;
	}

	modular operator + (modular m) {
		int res = val + m.val;
		return res - mod * (res >= mod);
	}

	bool operator < (modular m) const {
		return val < m.val;
	}

	friend istream& operator >> (istream &in, modular &m) {
		int x;
		in >> x;
		m = modular(x);
		return in;
	}

	friend ostream& operator << (ostream &out, modular m) {
		return out << m.val;
	}
};


const int MOD = 1e9 + 7;
using mint = modular<MOD>;

int n;
vector<vector<int>> g;
vector<pair<int, int>> edges;

vector<int> sz;

void dfs1(int v, int pr) {
	sz[v] = 1;
	for (auto u : g[v])
		if (u != pr) {
			dfs1(u, v);
			sz[v] += sz[u];
		}
}

void dfs2(int v, int pr) {
	for (auto u : g[v])
		if (u != pr) {
			edges.emplace_back(sz[u], n - sz[u]);
			int szv = sz[v], szu = sz[u];

			sz[v] -= sz[u];
			sz[u] += sz[v];

			dfs2(u, v);

			sz[v] = szv;
			sz[u] = szu;
		}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		g.clear();
		edges.clear();
		sz.clear();

		cin >> n;
		g.resize(n);
		for (int i = 1; i < n; i++) {
			int v, u;
			cin >> v >> u;
			v--, u--;
			g[v].push_back(u);
			g[u].push_back(v);
		}

		sz.resize(n);
		dfs1(0, 0);
		dfs2(0, 0);

		sort(edges.begin(), edges.end(), [](pair<int, int> &a, pair<int, int> &b) {
			return (ll) a.first * a.second > (ll) b.first * b.second;
		});

		int m;
		cin >> m;
		vector<mint> p(m);
		for (auto &x : p)
			cin >> x;
		while (p.size() < n - 1)
			p.push_back(1);

		sort(p.begin(), p.end());
		while (p.size() > n - 1) {
			mint a = p.back();
			p.pop_back();
			mint b = p.back();
			p.pop_back();
			p.push_back(a * b);
		}
		reverse(p.begin(), p.end());

		// cout << "edges =";
		// for (auto [v, u] : edges)
		// 	cout << " (" << v << ' ' << u << ')';
		// cout << endl;

		mint ans(0);
		for (int i = 0; i < n - 1; i++)
			ans = ans + p[i] * edges[i].first * edges[i].second;
		cout << ans << '\n';
	}
}