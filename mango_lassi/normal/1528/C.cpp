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
		ll get(int a, int b) { return get(b) - get(a-1); }

		// Assuming prefix sums are non-decreasing, finds last i s.t. get(i) <= v
		int search(ll v) {
			int res = 0;
			for (int h = 1<<30; h; h >>= 1) {
				if ((res | h) < val.size() && val[res | h] <= v) {
					res |= h;
					v -= val[res];
				}
			}
			return res - 1;
		}
};

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

int dfs(int i, vector<int>& cc, Fenwick& act, const HLD& hld, const vector<vector<int>>& g) {
	auto path = hld.path(i, 0);
	int p = -1;
	for (auto pr : path) {
		int a = pr.first;
		int b = pr.second;
		int s1 = act.get(b);
		int s0 = act.get(a-1);
		if (s0 == s1) continue;
		else {
			p = act.search(s1 - 1) + 1;
			break;
		}
	}

	int res = 0;
	if (p != -1) {
		if (cc[p] > 0) ++res;
		++cc[p];
	} else ++res;

	act.add(path[0].second, 1);

	int add = 0;
	for (int t : g[i]) {
		if (t < i) continue;
		add = max(add, dfs(t, cc, act, hld, g));
	}
	res += add;

	if (p != -1) --cc[p];
	act.add(path[0].second, -1);

	return res;
}

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> ga(n), gb(n);
	for (int i = 1; i < n; ++i) {
		int a;
		cin >> a;
		ga[a-1].push_back(i);
		ga[i].push_back(a-1);
	}
	for (int i = 1; i < n; ++i) {
		int b;
		cin >> b;
		gb[b-1].push_back(i);
		gb[i].push_back(b-1);
	}

	// Clique
	//	-> vertices are a subset of vertices on a path from the root to a leaf, on Soroush's tree
	//	-> subtrees of vertices are disjoint in Keshi's tree
	//	
	//	Point an edge up from every vertex in Soroush's tree, into the closest vertex above it that is its ancestor in Soroush's tree
	//	-> For every leaf, count number of leaves in the tree formed from these up-edges

	HLD hld(gb);
	Fenwick act(n);
	vector<int> cc(n, 0);

	int res = dfs(0, cc, act, hld, ga);
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}