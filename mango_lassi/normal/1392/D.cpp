#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = 1e9 + 7;

const int N = 2 * (int)1e5;
int dp[N][4]; // min ops for current state to be L, LL, R, or RR corresponding to 0, 1, 2, 3.

void solve() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	// LLL or RRR are not allowed. Anything else is fine
	// Loop over whether we change the first two, then DP the rest
	// 0 = L, 1 = R.

	int res = INF;
	for (int a = 0; a < 2; ++a) {
		for (int b = 0; b < 2; ++b) {
			int base = 0;
			if (a != (str[0] == 'R')) ++base;
			if (b != (str[1] == 'R')) ++base;

			for (int j = 0; j < 4; ++j) dp[1][j] = INF;
			dp[1][2*b + (a == b)] = base;

			for (int i = 1; i < n-1; ++i) {
				int t = (str[i+1] == 'R');

				// Change direction				
				dp[i+1][0] = min(dp[i][2], dp[i][3]) + t;
				dp[i+1][2] = min(dp[i][0], dp[i][1]) + (t ^ 1);

				// Maintain direction
				dp[i+1][1] = dp[i][0] + t;
				dp[i+1][3] = dp[i][2] + (1 - t);
			}

			int off = INF;
			if (a == 0) {
				// Those ending in R are fine
				off = min(off, min(dp[n-1][2], dp[n-1][3]));

				// If a != b, those ending in L but not LL are fine
				if (a != b) off = min(off, dp[n-1][0]);
			} else {
				// Those ending in L are fine
				off = min(off, min(dp[n-1][0], dp[n-1][1]));

				// If a != b, those ending in R but not RR are fine
				if (a != b) off = min(off, dp[n-1][2]);
			}
			res = min(res, off);
		}
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