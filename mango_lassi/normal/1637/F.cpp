#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
		// Returns interval corresponding to the subtree of node i
		pair<int, int> subtree(int i) const {
			return {ind[i], ind[i] + siz[i] - 1};
		}
};

template<class T>
class RangeMin {
	private:
		vector<T> seg;
		int n;
	public:	
		RangeMin(const vector<T>& v) : n(v.size()), seg(2*v.size()) {
			for (int i = 0; i < n; ++i) seg[i+n] = v[i];
			for (int i = n-1; i > 0; --i) seg[i] = min(seg[2*i], seg[2*i+1]);
		}
		T get(int a, int b) const {
			T res = seg[a + n]; // Change to INF to allow a > b
			for (a += n, b += n+1; a < b; a=(a+1)/2, b /= 2) {
				if (a & 1) res = min(res, seg[a]);
				if (b & 1) res = min(res, seg[b-1]);
			}
			return res;
		}
		void set(int i, T v) {
			seg[i + n] = v;
			for (i += n; i > 1; i /= 2) seg[i/2] = min(seg[i], seg[i^1]);
		}
};

// 1. Root at some max height vertex
// 2. Set height of each leaf i to h[i]
// 3. Loop vertices. At every vertex, if h[i] > max height in subtree, increment maximum height of a leaf in the subtree
// 	Now, everything but the root is satisfied. If the root is a leaf, set its weight to h[i]. Otherwise, increment weight of min-cost other subtree
ll dfs(int i, int p, RangeMin<pair<int, int>>& seg, const vector<int>& hs, const HLD& hld, const vector<vector<int>>& g) {
	ll res = 0;
	for (int t : g[i]) {
		if (t != p) res += dfs(t, i, seg, hs, hld, g);
	}

	auto rng = hld.subtree(i);
	auto pr = seg.get(rng.first, rng.second);
	if (-pr.first < hs[i]) {
		res += hs[i] + pr.first;
		int ind = hld.subtree(pr.second).first;
		seg.set(ind, {-hs[i], pr.second});
	}

	if (p == -1) {
		int b0 = 0, b1 = 0;
		for (int t : g[i]) {
			rng = hld.subtree(t);
			pr = seg.get(rng.first, rng.second);
			int off = -pr.first;

			if (off > b0) swap(off, b0);
			if (off > b1) swap(off, b1);
		}
		if (b1 < hs[i]) res += hs[i] - b1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> hs(n);
	for (int& h : hs) cin >> h;

	int r = 0;
	for (int i = 1; i < n; ++i) {
		if (hs[i] > hs[r]) r = i;
	}

	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;

		g[x].push_back(y);
		g[y].push_back(x);
	}

	HLD hld(g, r);
	vector<pair<int, int>> cur(n);
	for (int i = 0; i < n; ++i) {
		int ind = hld.subtree(i).first;
		cur[ind] = {0, i};
	}
	RangeMin<pair<int, int>> seg(cur);
	ll res = dfs(r, -1, seg, hs, hld, g);

	/*
	for (int i = 0; i < n; ++i) {
		cerr << -seg.get(hld.subtree(i).first, hld.subtree(i).first).first << ' ';
	}
	cerr << '\n';
	*/

	cout << res << '\n';
}