#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Fenwick {
	private:
		vector<ll> val;
	public:
		Fenwick(int n) : val(n+1, 0) {}

		// Adds v to index i
		void add(int i, ll v) {
			for (++i; i < val.size(); i += i & -i) {
				val[i] += v;
			}
		}

		// Calculates prefix sum up to index i
		ll get(int i) {
			ll res = 0;
			for (++i; i > 0; i -= i & -i) {
				res += val[i];
			}
			return res;
		}
};


class HLD {
	private:
		vector<int> par, siz, cmp, ind, rev;

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
				: par(g.size(), -1), siz(g.size(), 1), cmp(g.size(), r), ind(g.size()), rev(g.size()) {
			dfs1(r, g);
			int x = 0;
			dfs2(r, x, g);
			for (int i = 0; i < g.size(); ++i) rev[ind[i]] = i;
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
		int jmp(int a, int b) const {
			for (;; b = par[cmp[b]]) {
				if (ind[cmp[b]] <= ind[a]) return rev[ind[a] + 1];
				if (a == par[cmp[b]]) return cmp[b];
			}
		}
		int getRev(int i) const { return rev[i]; }
};

bool test(int i, int p, set<ll>& cur, const vector<ll>& vals, const vector<vector<int>>& g) {
	if (cur.find(vals[i]) != cur.end()) return false;
	cur.insert(vals[i]);
	for (auto t : g[i]) {
		if (t == p) continue;
		bool fail = !test(t, i, cur, vals, g);
		if (fail) return false;
	}
	cur.erase(vals[i]);
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> val(n);
	vector<pair<ll, int>> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> val[i];
		as[i] = {val[i], i};
	}
	sort(as.begin(), as.end());

	vector<vector<int>> g(n);
	for (int i = 0; i + 1 < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	// Three of a value: impossible or single node
	// Two of every value: intersection of paths
	HLD hld(g);

	int tar = 0;
	Fenwick fenw(n);
	for (int i = 0; i < n;) {
		int j = i;
		while(j < n && as[j].first == as[i].first) ++j;
		if (j-i >= 2) {
			for (int t = i; t < j; ++t) {
				int x = as[t].second;
				int y = as[(t == i ? i+1 : i)].second;

				auto pr = hld.subtree(x);
				auto cmp = hld.subtree(y);
				if (pr.first <= cmp.first && cmp.first <= pr.second) {
					int z = hld.jmp(x, y);
					pr = hld.subtree(z);

					++tar;
					fenw.add(pr.first, 1);
					fenw.add(pr.second + 1, -1);
				} else {
					fenw.add(pr.first, -1);
					fenw.add(pr.second + 1, 1);
				}
			}
		}
		i = j;
	}


	int res = 0;
	bool check = 0, fail = 0;
	for (int i = 0; i < n; ++i) {
		if (fenw.get(i) == tar) {
			++res;
			if (! check) {
				check = 1;
				set<ll> cur;
				fail = !test(hld.getRev(i), -1, cur, val, g);
			}
		}
	}
	if (fail) cout << 0 << '\n';
	else cout << res << '\n';
}