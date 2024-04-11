#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class DSU {
	private:
		vector<int> comp, siz, pt;
	public:
		DSU(int n) : comp(n), siz(n, 1), pt(n, 0) {
			for (int i = 0; i < n; ++i) comp[i] = i;
		}
		void getc(int i) {
			if (comp[i] != i) {
				getc(comp[i]);
				pt[i] ^= pt[comp[i]];
				comp[i] = comp[comp[i]];
			}
		}
		bool join(int a, int b, int p) {
			getc(a);
			getc(b);
			if (comp[a] == comp[b]) {
				int xr = (pt[a] ^ pt[b] ^ p);
				return xr == 0;
			}
			p ^= pt[a];
			p ^= pt[b];
			a = comp[a];
			b = comp[b];

			if (siz[a] < siz[b]) swap(a, b);
			siz[a] += siz[b];
			comp[b] = a;
			pt[b] = p;
			return true;
		}
};

void dfs(int i, int p, vector<pair<int, int>>& par, const vector<vector<int>>& g, const vector<pair<pair<int, int>, int>>& ed) {
	for (int ei : g[i]) {
		int t = ed[ei].first.first ^ ed[ei].first.second ^ i;
		if (t == p) continue;
		par[t] = {i, ei};
		dfs(t, i, par, g, ed);
	}
}

void solve() {
	int n, q;
	cin >> n >> q;
	
	vector<vector<int>> g(n);
	vector<pair<pair<int, int>, int>> ed(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		--a; --b;
		ed[i] = {{a, b}, w};
		g[a].push_back(i);
		g[b].push_back(i);
	}
	
	vector<pair<int, int>> par(n);
	par[0] = {-1, -1};
	dfs(0, -1, par, g, ed);

	bool works = 1;
	DSU dsu(n);
	vector<int> undet;
	for (int i = 1; i < n; ++i) {
		int ei = par[i].second;
		if (ed[ei].second == -1) {
			undet.push_back(i);
		} else {
			int p = __builtin_popcount(ed[ei].second) & 1;
			// cerr << "join " << i << ' ' << par[i].first << ' ' << p << '\n';
			works &= dsu.join(i, par[i].first, p);
		}
	}
	for (int qi = 0; qi < q; ++qi) {
		int a, b, p;
		cin >> a >> b >> p;
		--a; --b;
		// cerr << "join " << a << ' ' << b << ' ' << p << '\n';
		works &= dsu.join(a, b, p);
	}
	
	if (works) {
		cout << "YES\n";
		for (int a : undet) {
			int b = par[a].first;
			int ei = par[a].second;
			if (dsu.join(a, b, 0)) ed[ei].second = 0;
			else ed[ei].second = 1;
		}
		for (int i = 0; i < n - 1; ++i) {
			cout << ed[i].first.first + 1 << ' ' << ed[i].first.second + 1 << ' ' << ed[i].second << '\n';
		}
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}