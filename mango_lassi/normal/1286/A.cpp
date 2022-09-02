#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 100;
int dp[N+1][N+1][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j][0] = 2*n;
			dp[i][j][1] = 2*n;
		}
	}
	dp[0][0][0] = 0;
	dp[0][0][1] = 0;

	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		if (p == 0 || p % 2 == 0) {
			// Use even
			for (int j = 0; j < n; ++j) {
				dp[i+1][j+1][0] = min(dp[i][j][0], dp[i][j][1] + 1);
			}
		}
		if (p == 0 || p % 2 == 1) {
			// Use odd
			for (int j = 0; j <= n; ++j) {
				dp[i+1][j][1] = min(dp[i][j][1], dp[i][j][0] + 1);
			}
		}

		/*
		cerr << i << ":\n\t";
		for (int j = 0; j <= n; ++j) cerr << dp[i+1][j][0] << ' '; cerr << "\n\t";
		for (int j = 0; j <= n; ++j) cerr << dp[i+1][j][1] << ' '; cerr << '\n';
		*/
	}

	int even = n / 2;
	int res = min(dp[n][even][0], dp[n][even][1]);
	cout << res << '\n';
}