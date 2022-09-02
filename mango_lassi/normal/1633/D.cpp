#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = (int)1e9 + 7;
const int N = 1000, K = 1e6;
int hlp[K + 1];
int dp[N + 1];

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> bs(n), cs(n);
	for (int& b : bs) cin >> b;
	for (int& c : cs) cin >> c;

	int h = 0;
	hlp[0] = 0;
	for (int i = 0; i < n; ++i) {
		int x = dp[bs[i]];
		if (x >= INF) continue;

		for (int t = h + 1; t <= min(h + x, k); ++t) hlp[t] = 0;
		h = min(h + x, k);

		for (int v = h; v >= x; --v) hlp[v] = max(hlp[v], hlp[v - x] + cs[i]);
	}

	int res = 0;
	for (int i = 0; i <= h; ++i) res = max(res, hlp[i]);
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	dp[1] = 0;
	for (int v = 2; v <= N; ++v) dp[v] = INF;
	for (int v = 1; v <= N; ++v) {
		for (int x = 1; x <= v; ++x) dp[v + v/x] = min(dp[v + v/x], dp[v] + 1);
	}

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}