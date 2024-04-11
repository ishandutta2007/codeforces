#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

class DSU {
	private:
		vector<int> comp, siz;
	public:
		DSU(int n) : comp(n), siz(n, 1) {
			for (int i = 0; i < n; ++i) comp[i] = i;
		}
		int getc(int i) {
			if (comp[i] != i) comp[i] = getc(comp[i]);
			return comp[i];
		}
		bool join(int a, int b) {
			a = getc(a);
			b = getc(b);
			if (a == b) return false;

			if (siz[a] < siz[b]) swap(a, b);
			siz[a] += siz[b];
			comp[b] = a;
			return true;
		}
		int compSize(int i) { return siz[getc(i)]; }
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
			vector<pair<int, int>> le, ri;
			bool swp = 0;
			for (;; b = par[cmp[b]]) {
				if (ind[b] < ind[a]) {
					swap(a, b);
					swp ^= 1;
				}
				if (ind[cmp[b]] <= ind[a]) {
					if (swp) ri.push_back({ind[a], ind[b]});
					else le.push_back({ind[b], ind[a]});
					break;
				}
				if (swp) ri.push_back({ind[cmp[b]], ind[b]});
				else le.push_back({ind[b], ind[cmp[b]]});
			}
			vector<pair<int, int>> res;
			for (auto pr : le) res.push_back(pr);
			for (int i = (int)ri.size() - 1; i >= 0; --i) res.push_back(ri[i]);
			return res;
		}
		int index(int i) const { return ind[i]; }
};

int ith(int i, const vector<pair<int, int>>& path, const vector<int>& len) {
	int low = 0;
	int high = (int)path.size();
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		if (len[mid] > i) high = mid - 1;
		else low = mid;
	}
	i -= len[low];
	int d = (path[low].first <= path[low].second ? 1 : -1);
	return path[low].first + d * i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, r;
	cin >> n >> k >> r;

	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int> st(r);
	for (int i = 0; i < r; ++i) {
		cin >> st[i];
		--st[i];
	}

	// Build sets of connected rest stops
	DSU dsu(r);
	vector<int> dist(n, k+1), comp(n, -1);
	vector<int> sta;

	for (int i = 0; i < r; ++i) {
		dist[st[i]] = 0;
		comp[st[i]] = i;
		sta.push_back(st[i]);
	}

	for (int j = 0; j < sta.size(); ++j) {
		int i = sta[j];
		for (auto t : g[i]) {
			if (dist[t] > dist[i] + 1) {
				dist[t] = dist[i] + 1;
				comp[t] = comp[i];
				sta.push_back(t);
			} else if (comp[t] != -1 && dist[t] + dist[i] + 1 <= k) {
				dsu.join(comp[i], comp[t]);
			}
		}
	}

	/*
	cerr << "comps: ";
	for (auto v : comp) cerr << dsu.getc(v) << ' '; cerr << '\n';
	cerr << "dists: ";
	for (auto v : dist) cerr << v << ' '; cerr << '\n';
	*/

	// Build HLD to find i'th nodes on paths
	HLD hld(g);
	vector<int> rev(n);
	for (int i = 0; i < n; ++i) rev[hld.index(i)] = i;

	// for (int i = 0; i < n; ++i) cerr << rev[i] << ' '; cerr << '\n';

	int q;
	cin >> q;
	for (; q; --q) {
		int a, b;
		cin >> a >> b;
		--a; --b;

		// All vertices between a and b, as intervals,
		auto path = hld.path(a, b);
		int m = path.size();

		vector<int> len(m+1, 0);
		for (int i = 0; i < m; ++i) len[i+1] = len[i] + abs(path[i].first - path[i].second) + 1;

		/*
		cerr << "path: ";
		for (int i = 0; i < len[m]; ++i) cerr << rev[ith(i, path, len)] << ' ';
		cerr << '\n';
		*/

		if (len[m] - 1 <= k) {
			cout << "YES\n";
			continue;
		}

		// Find last component a can get to
		int low = -1;
		int high = len[m] - 1;
		while(low != high) {
			int mid = (low + high + 1) >> 1;
			int j = rev[ith(mid, path, len)];
			if (mid + dist[j] <= k) low = mid;
			else high = mid - 1;
		}
		int ca = (low == -1 ? -1 : dsu.getc(comp[rev[ith(low, path, len)]]));

		// Find last component b can get to
		low = 0;
		high = len[m];
		while(low != high) {
			int mid = (low + high) >> 1;
			int j = rev[ith(mid, path, len)];
			if ((len[m]-1 - mid) + dist[j] <= k) high = mid;
			else low = mid + 1;
		}
		int cb = (high == len[m] ? -1 : dsu.getc(comp[rev[ith(high, path, len)]]));

		if (ca == -1 || cb == -1 || ca != cb) cout << "NO\n";
		else cout << "YES\n";
	}
}