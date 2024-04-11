#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

// Segment tree for range addition and range sum.
class SegTree {
	private:
		const ll NEUT = 0; 
		vector<ll> seg, tag;
		int h = 1;

		// Returns length of interval corresponding to position i
		ll len(int i) { return h >> (31 - __builtin_clz(i)); }

		void apply(int i, ll v) {
			seg[i] = (seg[i] + v * len(i)) % MOD;
			if (i < h) tag[i] = (tag[i] + v) % MOD;
		}
		void push(int i) {
			if (tag[i] == 0) return;
			apply(2*i, tag[i]);
			apply(2*i+1, tag[i]);
			tag[i] = 0;
		}
		ll combine(ll a, ll b) { return (a + b) % MOD; }

		ll recGet(int a, int b, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return NEUT;
			if (a <= ia && ib <= b) return seg[i];
			push(i);
			int im = (ia + ib) >> 1;
			return combine(
				recGet(a, b, 2*i, ia, im),
				recGet(a, b, 2*i+1, im, ib));
		}
		void recApply(int a, int b, ll v, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return;
			if (a <= ia && ib <= b) apply(i, v);
			else {
				push(i);
				int im = (ia + ib) >> 1;
				recApply(a, b, v, 2*i, ia, im);
				recApply(a, b, v, 2*i+1, im, ib);
				seg[i] = combine(seg[2*i], seg[2*i+1]);
			}
		}
	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			seg.resize(2*h, NEUT);
			tag.resize(h, 0);
		}
		ll rangeSum(int a, int b) { return recGet(a, b+1, 1, 0, h); }
		void rangeAdd(int a, int b, ll v) { recApply(a, b+1, v, 1, 0, h); }
};

class HLD {
	private:
		vector<int> par, siz, cmp, ind;

		int dfs1(int i, vector<vector<int>>& g) {
			for (auto& t : g[i]) {
				if (t == par[i]) continue;
				par[t] = i;
				siz[i] += dfs1(t, g);
				if (siz[t] > siz[g[i][0]] || g[i][0] == par[i]) swap(t, g[i][0]);
			}
			return siz[i];
		}
		void dfs2(int i, int& x, const vector<vector<int>>& g) {
			ind[i] = x;
			++x;
			for (auto t : g[i]) {
				if (t == par[i]) continue;
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

ll modPow(ll a, ll b) {
	if (b & 1) return a * modPow(a, b-1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b / 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// O(n^2) algorithm is easy: Loop all pairs of nodes, count in how many they have same color, add to res
	// E = \sum_{i, j} dist(i, j) \frac{len(i \cap j)}{len(i) len(j)}
	//   = \sum_{c} \sum_{i, j} dist(i, j) I_{c \in i \cap j} / len(i) len(j)
	// ANS = E * \prod_{i} len(i)

	// Somehow calculate answer in a segment tree: Nodes become active and get deactivated only once.
	// Contribution of color c: Sum over every edge, weight below times weight above
	//                          Can also be calculated nodewise.

	// HLD with segment tree on edges: Store weight below and weight above as a and b. Support range sum and addition for a and b.

	ll colc = 1; // Number of colorings
	vector<ll> weight(n);
	vector<pair<int, int>> evs;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		evs.push_back({a, i+1});
		evs.push_back({b+1, -(i+1)});
		colc = (colc * (b-a+1)) % MOD;
		weight[i] = modPow(b-a+1, MOD - 2);
	}
	sort(evs.begin(), evs.end());

	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	HLD hld(g);

	ll cur = 0;
	ll res = 0;
	SegTree above(n), below(n);

	int c = 0;
	for (int j = 0; j < evs.size(); ++j) {
		int nc = evs[j].first;
		res = (res + cur * (nc - c)) % MOD;
		c = nc;

		int i = abs(evs[j].second) - 1;
		ll v = (evs[j].second < 0 ? MOD-1 : 1) * weight[i] % MOD;

		// Increment below for all edges above i
		// Increment above for all other edges
		vector<pair<int, int>> path = hld.path(i, 0);

		int pi = n-1;
		for (auto pr : path) {
			cur = (cur + v * below.rangeSum(pr.second + 1, pi)) % MOD;
			above.rangeAdd(pr.second + 1, pi, v);

			cur = (cur + v * above.rangeSum(pr.first, pr.second)) % MOD;
			below.rangeAdd(pr.first, pr.second, v);

			pi = pr.first - 1;
		}
	}

	res = (res * colc) % MOD;
	if (res < 0) res += MOD;
	cout << res << '\n';
}