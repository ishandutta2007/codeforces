#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Only positive values: Defeat bosses in decreasing order of ci
	// Only negative values:
	// 	Only thing that matters: How many times we add ci to the answer?
	//	-> make groups by putting the k+1 largest abs(ci) to be the last bosses in the groups, 
	//		Then the largest remaining k+1 abs(ci) to be the second last ones, and so on

	// If both:
	//	Still want all positive values in one run
	//	After the positive run, we use the same greedy strategy
	//	We first use smallest abs(ci) bad ones at the end of the positive run, then end it like all the others

	int n, k;
	cin >> n >> k;

	vector<ll> cs(n);
	for (ll& v : cs) cin >> v;
	sort(cs.begin(), cs.end());

	vector<ll> dp(n+1, 0);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) dp[i] = dp[i-1] + cs[i-1] * ((i - 1) / (k+1));

	ll res = -INF;

	ll cur = 0, off = 0;
	for (int i = n-1; i >= 0; --i) {
		off += cur;
		cur += cs[i];
		if (cur > 0) {
			res = max(res, off + dp[i] + cur * ((i + k) / (k + 1)));
		} else {
			res = max(res, off + dp[i] + cur * (i / (k + 1)));
		}
	}
	cout << res << '\n';
}