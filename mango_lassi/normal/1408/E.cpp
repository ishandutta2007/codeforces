#include <bits/stdc++.h>
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

void solve() {
	int m, n;
	cin >> m >> n;

	// If we can find a cycle with >= 2 colours, and some colour appears more than once in it, we can
	// just shortcut it to make a rainbow cycle. Therefore, we must make sure that all cycles are monochromatic.
	// Make a graph with n + m nodes, with a vertex for every set. Connect the sets to the vertices in the set.
	// This graph must be a tree, we pay for missing edges -> Find the maximum-cost spanning tree!

	vector<ll> as(m), bs(n);
	for (ll& v : as) cin >> v;
	for (ll& v : bs) cin >> v;
	
	ll res = 0;
	vector<pair<ll, pair<int, int>>> edges;
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		for (int t = 0; t < k; ++t) {
			int j;
			cin >> j;
			--j;
			res += as[i] + bs[j];
			edges.push_back({as[i] + bs[j], {i + n, j}});
		}
	}
	sort(edges.begin(), edges.end());
	reverse(edges.begin(), edges.end());

	DSU dsu(n + m);
	for (auto pr : edges) {
		if (dsu.join(pr.second.first, pr.second.second)) {
			res -= pr.first;
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}