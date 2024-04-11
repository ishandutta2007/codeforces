#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void dfs(int i, vector<int>& ord, vector<int>& vis, const vector<vector<int>>& g) {
	if (vis[i]) return;
	vis[i] = 2;
	for (auto t : g[i]) dfs(t, ord, vis, g);
	ord.push_back(i);
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
	}

	// Max depth for every node, initially 2
	// When handling vertex, if it's max depth is > 0, cap its children's max depth to its max depth - 1
	// Proof of correctness: look at where the numbers came from. Each origin closes at most 4/7.

	vector<int> ord;
	vector<int> dep(n, 0);
	for (int i = 0; i < n; ++i) dfs(i, ord, dep, g);

	reverse(ord.begin(), ord.end());
	for (auto i : ord) {
		if (dep[i] > 0) {
			for (auto t : g[i]) dep[t] = min(dep[t], dep[i] - 1);
		}
	}
		
	int res = 0;
	for (int i = 0; i < n; ++i) res += (dep[i] == 0);
	
	cout << res << '\n';
	for (int i = 0; i < n; ++i) {
		if (dep[i] == 0) cout << i+1 << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}
}