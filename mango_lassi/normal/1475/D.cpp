#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll m;
	cin >> n >> m;

	vector<ll> tmp(n);
	for (ll& a : tmp) cin >> a;

	array<vector<ll>, 2> as;
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		as[b-1].push_back(tmp[i]);
	}
	sort(as[0].begin(), as[0].end());
	sort(as[1].begin(), as[1].end());
	reverse(as[0].begin(), as[0].end());
	reverse(as[1].begin(), as[1].end());

	ll sum = 0;
	int j = as[1].size();
	for (auto v : as[1]) sum += v;

	int res = 3*n;
	for (int i = 0; i <= as[0].size(); ++i) {
		while(j > 0 && sum - as[1][j-1] >= m) {
			--j;
			sum -= as[1][j];
		}
		if (sum >= m) res = min(res, i + 2*j);
		if (i < as[0].size()) sum += as[0][i];
	}
	if (res >= 3*n) cout << -1 << '\n';
	else cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}