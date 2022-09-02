#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int, ll> recSolve(int i, const vector<ll>& ls, const vector<ll>& rs, const vector<vector<int>>& g) {
	pair<int, ll> res = {0, 0ll};
	for (int t : g[i]) {
		auto sub = recSolve(t, ls, rs, g);
		res.first += sub.first;
		res.second += sub.second;
	}

	res.second = min(res.second, rs[i]);
	if (res.second < ls[i]) {
		res.second = rs[i];
		++res.first;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> g(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		g[p-1].push_back(i);
	}
	vector<ll> ls(n), rs(n);
	for (int i = 0; i < n; ++i) cin >> ls[i] >> rs[i];
	
	int res = recSolve(0, ls, rs, g).first;
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}