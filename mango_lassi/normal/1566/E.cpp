#include <bits/stdc++.h>
using namespace std;
using ll = long long;

array<int, 3> dfs(int i, int p, const vector<vector<int>>& g) {
	array<int, 3> res;
	res[0] = 0;
	res[1] = 0;
	res[2] = 1;
	
	int lc = 0;
	for (int t : g[i]) {
		if (t == p) continue;
		auto sub = dfs(t, i, g);
		res[0] += sub[0];
		res[1] += sub[1];
		if (sub[2]) ++lc;
	}
	if (lc) {
		++res[0];
		res[1] += lc;
		res[2] = 0;
	}

	return res;
}

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	auto cou = dfs(0, -1, g);
	cout << cou[1] - cou[0] + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}