#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;

	vector<int> hs(n);
	for (int& h : hs) cin >> h;
	sort(hs.begin(), hs.end());
	int t = hs[n-1];

	// 2 cases: get all to t, or get all to t + 1
	ll res = INF;
	for (int t = hs[n-1]; t <= hs[n-1] + 1; ++t) {
		ll tot = 0, rem = 0;
		for (int i = 0; i < n; ++i) {
			tot += t - hs[i];
			rem += (t - hs[i]) & 1;
		}
		ll req_rem = max(0ll, 2 * rem - 1);
		ll req_tot = 2 * (tot / 3) + (tot % 3);
		res = min(res, max(req_rem, req_tot));
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}