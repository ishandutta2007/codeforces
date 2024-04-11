#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<pair<pair<ll, ll>, int>> as(n);
	for (auto& pr : as) cin >> pr.first.first;
	for (auto& pr : as) cin >> pr.first.second;
	for (int i = 0; i < n; ++i) as[i].second = i;
	sort(as.begin(), as.end());

	vector<bool> res(n, 0);
	res[as[n-1].second] = 1;
	ll min_win_second = as[n-1].first.second;

	int j = n-1;
	for (int i = n-2; i >= 0; --i) {
		if (as[i].first.second > min_win_second) {
			for (int t = i; t < j; ++t) {
				res[as[t].second] = 1;
				min_win_second = min(min_win_second, as[t].first.second);
			}
			j = i;
		}
	}

	for (int i = 0; i < n; ++i) cout << res[i]; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}