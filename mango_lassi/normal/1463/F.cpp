#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono; 
using ll = long long;

const int K = 22;
ll dp[2][1<<K];

void solve() {
	ll n;
	int x, y;
	cin >> n >> x >> y;
	if (x > y) swap(x, y);
	int s = x + y;

	for (int i = 0; i < s; ++i) {
		ll v = (n-i + (s-1)) / s;
		int b = (i & 1);
		for (int m = 0; m < (1 << y); ++m) dp[b ^ 1][m] = 0;
		for (int m = 0; m < (1 << y); ++m) {
			if ((!(m & 1)) && (!(m & (1 << (y - x))))) {
				int ind = ((m >> 1) | (1 << (y-1)));
				dp[b^1][ind] = max(dp[b^1][ind], dp[b][m] + v);
			}
			dp[b^1][m >> 1] = max(dp[b^1][m >> 1], dp[b][m]);
		}
	}
	ll res = 0;
	for (int m = 0; m < (1 << y); ++m) {
		res = max(res, (ll)dp[s & 1][m]);
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}