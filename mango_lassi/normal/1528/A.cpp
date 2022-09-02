#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> dfs(int i, int p, const vector<pair<ll, ll>>& lrs, const vector<vector<int>>& g) {
	pair<ll, ll> res = {0, 0};
	for (int t : g[i]) {
		if (t == p) continue;
		auto sub = dfs(t, i, lrs, g);
		res.first += max(sub.first + abs(lrs[t].first - lrs[i].first), sub.second + abs(lrs[t].second - lrs[i].first));
		res.second += max(sub.first + abs(lrs[t].first - lrs[i].second), sub.second + abs(lrs[t].second - lrs[i].second));
	}
	return res;
}

void solve() {
	int n;
	cin >> n;

	vector<pair<ll, ll>> lrs(n);
	for (auto& pr : lrs) cin >> pr.first >> pr.second;

	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	// Always optimal to have either MAX VALUE or MIN VALUE
	auto res = dfs(0, -1, lrs, g);
	cout << max(res.first, res.second) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}