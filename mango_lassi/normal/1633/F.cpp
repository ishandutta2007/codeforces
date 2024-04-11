#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
		int lca(int a, int b) const {
			for (;; b = par[cmp[b]]) {
				if (ind[b] < ind[a]) swap(a, b);
				if (ind[cmp[b]] <= ind[a]) return a;
			}
		}

		int revInd(int i) const { return rev[i]; }
};

class SegTree {
	private:
		array<ll, 4> NEUT = {0ll, 0ll, 0ll, 0ll};
		vector<array<ll, 4>> seg;
		vector<int> tag;
		int h = 1;

		void apply(int i, int v) {
			if (v & 2) {
				swap(seg[i][0], seg[i][2]);
				swap(seg[i][1], seg[i][3]);
			}
			if (v & 1) {
				swap(seg[i][0], seg[i][1]);
				swap(seg[i][2], seg[i][3]);
			}
			if (i < h) tag[i] ^= v;
		}
		void push(int i) {
			if (tag[i] == 0) return;
			apply(2*i, tag[i]);
			apply(2*i+1, tag[i]);
			tag[i] = 0;
		}
		array<ll, 4> combine(const array<ll, 4>& a, const array<ll, 4>& b) {
			array<ll, 4> res;
			for (int j = 0; j < 4; ++j) res[j] = a[j] + b[j];
			return res;
		}

		array<ll, 4> recGet(int a, int b, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return NEUT;
			if (a <= ia && ib <= b) return seg[i];
			push(i);
			int im = (ia + ib) >> 1;
			return combine(
				recGet(a, b, 2*i, ia, im),
				recGet(a, b, 2*i+1, im, ib));
		}
		void recApply(int a, int b, int v, int i, int ia, int ib) {
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
		SegTree(const vector<ll>& vs) {
			int n = vs.size();
			while(h < n) h *= 2;

			seg.resize(2*h, NEUT);
			tag.resize(h, 0);
			for (int i = 0; i < n; ++i) seg[h + i][0] = vs[i];
			for (int i = h-1; i > 0; --i) seg[i] = combine(seg[2*i], seg[2*i+1]);
		}
		array<ll, 4> rangeGet(int a, int b) { return recGet(a, b+1, 1, 0, h); }
		void rangeXor(int a, int b, int v) { recApply(a, b+1, v, 1, 0, h); }
};

void dfs(int i, int p, vector<int>& par, vector<ll>& val, const vector<vector<pair<int, int>>>& wg) {
	for (auto pr : wg[i]) {
		int t = pr.first;
		if (t == p) continue;
		par[t] = i;
		val[t] = pr.second;
		dfs(t, i, par, val, wg);
	}
}

int dfsMatch(int i, int p, vector<ll>& res, const vector<int>& act, const vector<ll>& val, const vector<vector<int>>& g) {
	int siz = 1;
	for (int t : g[i]) {
		if (t == p || !act[t]) continue;
		siz += dfsMatch(t, i, res, act, val, g);
	}
	if (siz & 1) res.push_back(val[i]);
	return siz;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	vector<vector<pair<int, int>>> wg(n);
	for (int i = 0; i + 1 < n; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		wg[x].emplace_back(y, i + 1);
		wg[y].emplace_back(x, i + 1);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	HLD hld(g, 0);
	vector<int> par(n, -1);
	vector<ll> val(n, 0);
	dfs(0, -1, par, val, wg);
	
	vector<ll> ord_val(n);
	for (int i = 0; i < n; ++i) ord_val[hld.subtree(i).first] = val[i];

	vector<ll> ones(n, 1ll);
	SegTree counts(ones), sums(ord_val);
	sums.rangeXor(0, 0, 1);

	// Number of light children with odd size subtrees
	vector<int> cou_light_ch(n, 0), act(n, 0);
	act[0] = 1;
	int cou_act = 1;
	int cou_2ch = 0;

	while(true) {
		int op;
		cin >> op;
		if (op == 3) break;
		else if (op == 1) {
			int i;
			cin >> i;
			--i;

			act[i] = 1;
			++cou_act;

			auto path = hld.path(0, i);
			for (auto pr : path) {
				int a = pr.first;
				int b = pr.second;
				sums.rangeXor(a, b, 1);
				if (a < b) counts.rangeXor(a, b - 1, 1);

				int x = hld.revInd(a);
				if (par[x] != -1) {
					int j = par[x];
					int t = hld.subtree(j).first;
					if (sums.rangeGet(a, a)[0]) {
						// After this change, the subtree now has even size (it used to have odd size)
						--cou_light_ch[j];
						if (cou_light_ch[j] == 1) --cou_2ch;
						if (cou_light_ch[j] == 0) counts.rangeXor(t, t, 2);
					} else {
						// After this change, the subtree now has even size (it used to have odd size)
						++cou_light_ch[j];
						if (cou_light_ch[j] == 2) ++cou_2ch;
						if (cou_light_ch[j] == 1) counts.rangeXor(t, t, 2);
					}
				}
			}

			if (cou_act % 2 == 0 && cou_2ch == 0 && counts.rangeGet(0, n-1)[3] == 0) {
				ll sum = sums.rangeGet(0, n-1)[1];
				cout << sum << endl;
			} else {
				cout << 0 << endl;
			}
		} else if (op == 2) {
			if (cou_act % 2 == 0 && cou_2ch == 0 && counts.rangeGet(0, n-1)[3] == 0) {
				vector<ll> res;
				dfsMatch(0, -1, res, act, val, g);
				sort(res.begin(), res.end());

				cout << res.size() << ' ';
				for (ll v : res) cout << v << ' '; cout << endl;
			} else {
				cout << 0 << endl;
			}
		}
	}
}