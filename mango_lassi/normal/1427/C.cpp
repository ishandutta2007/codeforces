#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 1e5;
int dp[M+1];
int pref_dp[M+1];
int times[M+1];
int xs[M+1];
int ys[M+1];

void solve() {
	int n, m;
	cin >> n >> m;
	int k = 2*n;

	xs[0] = 1;
	ys[0] = 1;
	for (int i = 1; i <= m; ++i) {
		cin >> times[i] >> xs[i] >> ys[i];

		dp[i] = -M;
		for (int j = max(0, i-k); j < i; ++j) {
			int dist = abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]);
			if (dist <= times[i] - times[j]) dp[i] = max(dp[i], dp[j]);
		}
		if (i >= k) dp[i] = max(dp[i], pref_dp[i-k]);
		++dp[i];

		pref_dp[i] = max(dp[i], pref_dp[i-1]);
	}
	cout << pref_dp[m] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
	
}