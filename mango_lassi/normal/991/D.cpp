#include <iostream>
#include <string>

const int N = 100;
bool wall[N][2];
int dp[N][2][2];

int solve(int n, bool a, bool b) {
	if (n < 0) return 0;
	if (dp[n][a][b] != -1) return dp[n][a][b];
	int res = 0;

	bool na = wall[n][0];
	bool nb = wall[n][1];

	res = std::max(res, solve(n-1, na, nb));
	if ((!a) && (!b)) {
		if (!na) {
			res = std::max(res, 1 + solve(n-1, true, nb));
		}
		if (!nb) {
			res = std::max(res, 1 + solve(n-1, na, true));
		}
	}
	if ((!na) && (!nb)) {
		if ((!a) || (!b)) {
			res = std::max(res, 1 + solve(n-1, true, true));
		}
	}

	// std::cout << "solve(" << n << "," << a << "," << b << "):" << res << '\n';
	dp[n][a][b] = res;
	return res;
}

int main() {
	int n;
	for (int i = 0; i < 2; ++i) {
		std::string row;
		std::cin >> row;
		n = row.size();
		for (int j = 0; j < n; ++j) {
			wall[j][i] = (row[j] == 'X');
		}
	}
	for (int i = 0; i < n; ++i) {
		dp[i][0][0] = -1;
		dp[i][0][1] = -1;
		dp[i][1][0] = -1;
		dp[i][1][1] = -1;
	}
	std::cout << solve(n-1, true, true) << '\n';
}