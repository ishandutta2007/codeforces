#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> vals(n);
	for (int& v : vals) cin >> v;

	// Make input into a permutation, while maintaining inversions
	vector<pair<int, int>> ord(n);
	for (int i = 0; i < n; ++i) ord[i] = {vals[i], i};
	sort(ord.begin(), ord.end());
	for (int i = 0; i < n; ++i) vals[ord[i].second] = i;

	vector<vector<int>> g(n);
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (vals[j] < vals[i]) g[i].push_back(j);
		}
	}


	vector<pair<int, int>> res;
	for (int i = 0; i < n; ++i) {
		// Swap minimum to this position without creating new inversions
		// (though some inversions might become redundant)
		int m = g[i].size();
		vector<pair<int, int>> perm(m);
		for (int j = 0; j < m; ++j) perm[j] = {vals[g[i][j]], g[i][j]};
		sort(perm.begin(), perm.end());

		for (int j = m-1; j >= 0; --j) {
			res.emplace_back(i, perm[j].second);
			swap(vals[i], vals[perm[j].second]);
		}
	}
	
	cout << res.size() << '\n';
	for (auto pr : res) cout << pr.first + 1 << ' ' << pr.second + 1 << '\n';
	// for (int i = 0; i < n; ++i) cout << vals[i] << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}