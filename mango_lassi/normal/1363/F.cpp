#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = 1e9 + 7;

const int N = 2000;
const int C = 26;
int dp[N+1][N+1];
int cou[2][N+1][C];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		for (int c = 0; c < C; ++c) {
			cou[0][i][c] = 0;
			cou[1][i][c] = 0;
		}
		for (int j = 0; j <= n; ++j) dp[i][j] = INF;
	}

	string tar, str;
	cin >> tar >> str;

	for (int i = 0; i < n; ++i) {
		for (int c = 0; c < C; ++c) {
			cou[0][i+1][c] = cou[0][i][c] + (c == (str[i] - 'a'));
			cou[1][i+1][c] = cou[1][i][c] + (c == (tar[i] - 'a'));
		}
	}

	// Start making "str" into "tar" from the end
	// In one operation, move character to the left an arbitrary amount
	// DP[a][b]: minimum number of moves we can make to prefix of length "a" of "str"
	//	to make it equal to prefix of length "b" of "tar", with other characters "floating"
	//	A character is "floating" if we have applied a "move to the right" operation to it, but
	//	have not placed it yet.

	dp[0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			// Current state: we have applied operations to str[0, i) to make it equal to tar[0, j)

			// Matching character
			if (i < n && j < n && str[i] == tar[j]) {
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
			}

			// Eat a character
			if (i < n) {
				dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
			}

			// Pop a floating character
			if (j < n) {
				int c = tar[j] - 'a';
				if (cou[0][i][c] >= cou[1][j+1][c]) dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
			}
		}
	}

	if (dp[n][n] < INF) cout << dp[n][n] << '\n';
	else cout << -1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}
}