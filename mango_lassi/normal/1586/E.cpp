#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int i, int p, vector<int>& par, vector<int>& dep, const vector<vector<int>>& g) {
	dep[i] = dep[p] + 1;
	par[i] = p;
	for (int t : g[i]) {
		if (dep[t] == -1) dfs(t, i, par, dep, g);
	}
}

void solve() {
	// Every query xors the parity of sum of edges adjacent to A and B by one
	// Odd xor of weights of adjacent edges -> at least one odd weight adjacent edge
	// -> to have all edge weights 0, we need an even number of paths starting from every vertex
	
	// Assume a even number of paths starting from every vertex
	// Then making all paths run along a spanning tree is enough

	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	int q;
	cin >> q;

	vector<int> deg(n, 0);
	vector<pair<int, int>> qs(q);
	for (int qi = 0; qi < q; ++qi) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		qs[qi] = {a, b};
		++deg[a];
		++deg[b];
	}
	
	int odds = 0;
	for (int i = 0; i < n; ++i) odds += (deg[i] & 1);
	
	if (odds == 0) {
		cout << "YES\n";
		vector<int> par(n, -1), dep(n, -1);
		dfs(0, -1, par, dep, g);

		for (int qi = 0; qi < q; ++qi) {
			int a = qs[qi].first;
			int b = qs[qi].second;
			vector<int> ap, bp;
			while(a != b) {
				if (dep[a] > dep[b]) {
					ap.push_back(a);
					a = par[a];
				} else {
					bp.push_back(b);
					b = par[b];
				}
			}

			ap.push_back(a);
			reverse(bp.begin(), bp.end());

			cout << ap.size() + bp.size() << '\n';
			for (int i : ap) cout << i + 1 << ' ';
			for (int i : bp) cout << i + 1 << ' ';
			cout << '\n';
		}
	} else {
		cout << "NO\n";
		cout << (odds / 2) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}