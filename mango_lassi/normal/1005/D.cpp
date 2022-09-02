#include <iostream>
using namespace std;

const int INF = 1e9;
const int N = 2 * (int)1e5;
const int M = 3;
string num;

int dp[N+1][M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> num;
	int n = num.size();

	dp[n][0] = -1;
	for (int r = 1; r < M; ++r) dp[n][r] = -INF;

	int prev_max = 0;
	for (int i = n-1; i >= 0; --i) {
		for (int r = 0; r < M; ++r) dp[i][r] = -INF;

		int add = (num[n-1-i] - '0') % M;

		// Multiple leading zeroes is not a problem, since that is never optimal
		// Make a cut
		dp[i][add] = prev_max;

		// Do not make a cut
		for (int r = 0; r < M; ++r) {
			int rem = (10 * r + add) % M;
			dp[i][rem] = max(dp[i][rem], dp[i+1][r]);
		}

		// Find best
		prev_max = dp[i][0] + 1;
		for (int r = 1; r < M; ++r) prev_max = max(prev_max, dp[i][r]);
	}

	cout << prev_max << '\n';
}