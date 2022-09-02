#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n = 5 * (int)1e5;
	vector<int> rep(n);
	for (int i = 0; i < n; ++i) rep[i] = i;

	int q;
	cin >> q;
	vector<pair<int, int>> ops(q);
	for (auto& pr : ops) {
		int t;
		cin >> t;
		if (t == 1) pr.first = 0;
		else cin >> pr.first;
		cin >> pr.second;
		--pr.first; --pr.second;
	}
	reverse(ops.begin(), ops.end());

	vector<int> res;
	for (auto pr : ops) {
		if (pr.first == -1) res.push_back(rep[pr.second]);
		else rep[pr.first] = rep[pr.second];
	}
	reverse(res.begin(), res.end());

	for (int v : res) cout << v + 1 << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}