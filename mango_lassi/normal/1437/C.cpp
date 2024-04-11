#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

const int N = 200;
ll dp[N+1][2*N];

void solve() {
	int n;
	cin >> n;

	vector<int> ts(n);
	for (int& t : ts) cin >> t;
	sort(ts.begin(), ts.end());

	for (int i = 1; i <= n; ++i) {
		int t = ts[i-1];
		for (int x1 = 0; x1 <= 2*n; ++x1) {
			ll off = INF;
			for (int x0 = 0; x0 < x1; ++x0) {
				off = min(off, dp[i-1][x0]);
			}
			dp[i][x1] = off + abs(t - x1);
		}
	}
	ll res = INF;
	for (int x = 0; x <= 2*n; ++x) res = min(res, dp[n][x]);
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int ti = 0; ti < n; ++ti) solve();
}