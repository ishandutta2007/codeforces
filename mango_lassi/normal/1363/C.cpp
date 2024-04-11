#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	--x;

	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	if ((g[x].size() <= 1) || (n % 2 == 0)) cout << "Ayush\n";
	else cout << "Ashish\n";
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