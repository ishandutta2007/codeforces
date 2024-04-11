#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (int)1e9 + 7;

void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	int res = 0;
	array<int, 4> dp;
	dp[0] = 0; dp[1] = -INF, dp[2] = -INF, dp[3] = -INF;

	for (int i = 0; i < n; ++i) {
		int zc = (a[i] == '0') + (b[i] == '0');
		int oc = (a[i] == '1') + (b[i] == '1');
		int off = (zc ? 1 : 0) | (oc ? 2 : 0);

		array<int, 4> nxt;
		for (int j = 0; j < 4; ++j) nxt[j] = -INF;
		for (int j = 0; j < 4; ++j) nxt[j | off] = max(nxt[j | off], dp[j]);
		for (int j = 1; j < 4; ++j) nxt[0] = max(nxt[0], nxt[j] + (j & 1) + (j == 3));
		dp = nxt;
	}
	cout << dp[0] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}