#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}
template<class T>
T rand() {
	return uniform_int_distribution<T>()(rng);
}

class HLD {
	private:
		vector<int> par, siz, cmp, ind;

		int dfs1(int i, vector<vector<int>>& g) {
			for (auto& t : g[i]) if (t != par[i]) {
				par[t] = i;
				siz[i] += dfs1(t, g);
				if (siz[t] > siz[g[i][0]] || g[i][0] == par[i]) swap(t, g[i][0]);
			}
			return siz[i];
		}
		void dfs2(int i, int& x, const vector<vector<int>>& g) {
			ind[i] = x;
			++x;
			for (auto t : g[i]) if (t != par[i]) {
				cmp[t] = (x == ind[i]+1 ? cmp[i] : t);
				dfs2(t, x, g);
			}
		}
	public:
		// Assumes the tree is connected and r is the root
		HLD(vector<vector<int>> g, int r = 0)
				: par(g.size(), -1), siz(g.size(), 1), cmp(g.size(), r), ind(g.size()) {
			dfs1(r, g);
			int x = 0;
			dfs2(r, x, g);
		}
		// Returns intervals corresponding to the path between a and b in descending order
		vector<pair<int, int>> path(int a, int b) const {
			vector<pair<int, int>> res;
			for (;; b = par[cmp[b]]) {
				if (ind[b] < ind[a]) swap(a, b);
				if (ind[cmp[b]] <= ind[a]) {
					res.push_back({ind[a], ind[b]});
					return res;
				}
				res.push_back({ind[cmp[b]], ind[b]});
			}
		}
		// Returns interval corresponding to the subtree of node i
		pair<int, int> subtree(int i) const {
			return {ind[i], ind[i] + siz[i] - 1};
		}
		int lca(int a, int b) const {
			for (;; b = par[cmp[b]]) {
				if (ind[b] < ind[a]) swap(a, b);
				if (ind[cmp[b]] <= ind[a]) return a;
			}
		}
};

class Fenwick {
	private:
		vector<ll> val;
	public:
		Fenwick(int n) : val(n+1, 0) {}

		// Adds v to index i
		void add(int i, ll v) {
			for (++i; i < val.size(); i += i & -i) {
				val[i] ^= v;
			}
		}

		// Calculates prefix sum up to index i
		ll get(int i) {
			ll res = 0;
			for (++i; i > 0; i -= i & -i) {
				res ^= val[i];
			}
			return res;
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> as(n);
	vector<vector<int>> apps(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		--as[i];
		apps[as[i]].push_back(i);
	}

	vector<ll> codes(n);
	for (ll& v : codes) v = rand(ll(0), INF);

	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}
	HLD hld(g);

	vector<pair<pair<int, int>, int>> data(q);
	vector<pair<int, int>> qs(q);
	for (int qi = 0; qi < q; ++qi) {
		int s, t, a, b;
		cin >> s >> t >> a >> b;
		--s; --t; --a; --b;
		data[qi] = make_pair(make_pair(s, t), b);
		qs[qi] = make_pair(a, qi);
	}


	int h = 1;
	while(2*h <= n) h <<= 1;
	for (; h > 0; h >>= 1) {
		sort(qs.begin(), qs.end());

		Fenwick fenw(n);
		for (int j = 0; j < h; ++j) {
			for (auto i : apps[j]) {
				auto s = hld.subtree(i);
				fenw.add(s.first, codes[j]);
				fenw.add(s.second + 1, codes[j]);
			}
		}

		int ind = 0;
		for (int a = 0; a < n; ++a) {
			while(ind < qs.size() && qs[ind].first == a) {
				auto dt = data[qs[ind].second];
				int x = dt.first.first;
				int y = dt.first.second;
				int z = hld.lca(x, y);
				ll v = fenw.get(hld.subtree(x).first) ^ fenw.get(hld.subtree(y).first);
				if (a <= as[z] && as[z] < a + h) v ^= codes[as[z]];

				if (v == 0) qs[ind].first += h;
				++ind;
			}
			for (auto i : apps[a]) {
				auto s = hld.subtree(i);
				fenw.add(s.first, codes[a]);
				fenw.add(s.second + 1, codes[a]);
			}
			if (a + h < n) {
				for (auto i : apps[a + h]) {
					auto s = hld.subtree(i);
					fenw.add(s.first, codes[a + h]);
					fenw.add(s.second + 1, codes[a + h]);
				}
			}
		}
	}

	for (auto& pr : qs) swap(pr.first, pr.second);
	sort(qs.begin(), qs.end());

	for (int j = 0; j < qs.size(); ++j) {
		int r = qs[j].second;
		auto dt = data[j];
		if (dt.second < r) cout << -1 << '\n';
		else cout << r + 1 << '\n';
	}
}