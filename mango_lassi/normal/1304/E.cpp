#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

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
		int lca(int a, int b) const {
			for (;; b = par[cmp[b]]) {
				if (ind[b] < ind[a]) swap(a, b);
				if (ind[cmp[b]] <= ind[a]) return a;
			}
		}
};

void calcDepth(int i, int p, vector<int>& d, const vector<vector<int>>& g) {
	d[i] = d[p] + 1;
	for (auto t : g[i]) {
		if (t != p) calcDepth(t, i, d, g);
	}
}

int dist(int a, int b, const vector<int>& depth, const HLD& hld) {
	int c = hld.lca(a, b);
	// cerr << "dist(" << a << ' ' << b << "): LCA " << c << ", depth " << depth[a] << ' ' << depth[b] << ' ' << depth[c] << '\n';
	return depth[a] + depth[b] - 2 * depth[c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	HLD hld(g);

	vector<int> depth(n, 0);
	calcDepth(0, 0, depth, g);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		--x; --y; --a; --b;

		// Try to not use the cycle
		int ini = dist(a, b, depth, hld);

		if (ini <= k && (ini % 2 == k % 2)) {
			cout << "YES\n";
			continue;
		}
		// We must use the cycle

		int z = hld.lca(x, y);
		int len = (depth[x] + depth[y] + 1 - 2 * depth[z]); // cycle length

		// Point where a connects to the cycle
		int acc_a1 = hld.lca(a, x);
		int acc_a2 = hld.lca(a, y);
		int acc_a = (depth[acc_a1] > depth[acc_a2] ? acc_a1 : acc_a2);
		if (depth[acc_a] < depth[z]) acc_a = z;

		// Point where b connects to the cycle
		int acc_b1 = hld.lca(b, x);
		int acc_b2 = hld.lca(b, y);
		int acc_b = (depth[acc_b1] > depth[acc_b2] ? acc_b1 : acc_b2);
		if (depth[acc_b] < depth[z]) acc_b = z;
		
		// Distance over and under the cycle
		int d0 = dist(acc_a, acc_b, depth, hld);
		int d1 = len - d0;

		int base = dist(a, acc_a, depth, hld) + dist(b, acc_b, depth, hld);
		int off = base + d1;

		/*
		cerr << a << ": " << acc_a1 << ' ' << acc_a2 << " -> " << acc_a << '\n';
		cerr << b << ": " << acc_b1 << ' ' << acc_b2 << " -> " << acc_b << '\n';
		*/

		if (off <= k && (off % 2 == k % 2)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}