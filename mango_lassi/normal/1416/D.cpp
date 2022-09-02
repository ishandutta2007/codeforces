#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>
class RangeMin {
	private:
		vector<T> seg;
		int n;

		int recf(int a, T v) const {
			while(a < n) a = 2*a + (seg[2*a] > v);
			return a - n;
		}
	public:	
		RangeMin(const vector<T>& v) : n(v.size()), seg(2*v.size()) {
			for (int i = 0; i < n; ++i) seg[i+n] = v[i];
			for (int i = n-1; i > 0; --i) seg[i] = min(seg[2*i], seg[2*i+1]);
		}

		// Returns smallest i >= a s.t. val[i] <= v, or n if there is none
		int search(int a, T v) const {
			int b = 2*n, r = 2*n;
			for (a += n; a < b; a=(a+1)/2, b /= 2) {
				if ((a & 1) && seg[a] <= v) return recf(a, v);
				if ((b & 1) && seg[b-1] <= v) r = b-1;
			}
			return recf(r, v);
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
			rev[x] = i;
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
		}

		int revInd(int i) {
			return rev[i];
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
};

class DSU {
	private:
		vector<int> comp;
	public:
		DSU(int n) : comp(n) {
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
			if (a < b) swap(a, b);

			comp[b] = a;
			return true;
		}
};


void solve() {
	int n, m, q;
	cin >> n >> m >> q;

	vector<int> ps(n);
	for (int& v : ps) cin >> v;
	
	vector<pair<int, pair<int, int>>> edges(m + n-1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		edges[i] = {q, {a, b}};
	}
	for (int i = m; i < m+n-1; ++i) edges[i] = {-1, {i-m, i-m+1}};

	vector<pair<int, int>> que;
	for (int t = 0; t < q; ++t) {
		int op, x;
		cin >> op >> x;
		--x;

		if (op == 1) {
			que.push_back({t, x});
		} else {
			edges[x].first = t;
		}
	}
	sort(edges.begin(), edges.end());

	int r = n;
	vector<int> tmp(2*n-1, q);
	vector<vector<int>> g(2*n-1);
	DSU dsu(2*n-1);
	while(! edges.empty()) {
		auto ed = edges.back();
		edges.pop_back();

		int t = ed.first;
		int a = ed.second.first;
		int b = ed.second.second;

		// cerr << "edge " << a << ' ' << b << " at time " << t << '\n';
		if (dsu.getc(a) == dsu.getc(b)) continue;

		tmp[r] = t;

		int va = dsu.getc(a);
		int vb = dsu.getc(b);
		g[r].push_back(va);
		g[r].push_back(vb);
		g[va].push_back(r);
		g[vb].push_back(r);

		dsu.join(va, r);
		dsu.join(vb, r);

		++r;
	}
	--r;

	/*
	for (auto v : tmp) cout << v << ' '; cout << '\n';
	for (int i = 0; i < 2*n-1; ++i) {
		cout << "\t" << i << ": ";
		for (auto t : g[i]) cout << t << ' '; cout << '\n';
	}
	cout << endl;
	cout << "root: " << r << endl;
	*/
	
	HLD hld(g, r);
	vector<pair<int, int>> vals(2*n-1);
	for (int i = 0; i < 2*n-1; ++i) vals[i] = {0, i};
	for (int i = 0; i < n; ++i) {
		int j = hld.subtree(i).first;
		vals[j].first = -ps[i];
	}
	RangeMin<pair<int, int>> seg(vals);

	vector<int> times(2*n-1);
	for (int i = 0; i < 2*n-1; ++i) {
		int j = hld.subtree(i).first;
		times[j] = tmp[i];
		// cerr << j << ' ';
	}
	// cerr << '\n';

	// for (auto v : times) cerr << v << ' '; cerr << '\n';

	// Answer queries
	for (auto qr : que) {
		int t = qr.first;
		int x = qr.second;
		
		int root = -1;
		vector<pair<int, int>> path = hld.path(x, r);
		for (auto itv : path) {
			int a = itv.first;
			int b = itv.second;
			// cerr << "path: " << a << ' ' << b << '\n';
			if (times[a] >= t) root = a;
			else {
				int low = a;
				int high = b+1;
				while(low != high) {
					int mid = (low + high) >> 1;
					// cerr << "bins " << low << ' ' << high << ' ' << mid << ' ' << times[mid] << ' ' << t << '\n';
					if (times[mid] >= t) high = mid;
					else low = mid + 1;
				}
				if (high <= b) root = high;
				break;
			}
		}
		// cerr << "times[root]: " << times[root] << ' ' << root << '\n';
		root = hld.revInd(root);

		pair<int, int> subtree = hld.subtree(root);
		pair<int, int> pr = seg.get(subtree.first, subtree.second);
		cout << -pr.first << '\n';
		seg.set(pr.second, {0, pr.second});

		// cerr << t << ' ' << x << ": " << root << " (" << subtree.first << ' ' << subtree.second << ")" << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}