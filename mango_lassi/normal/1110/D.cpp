#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int M = 10 + (int)1e6;
int cou[M];
int dp[M + 1][3][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		++cou[v-1];
	}

	// Can assume we never take more than two pairs from three back-to-back ones
	// DP on how many were taken at x-1 and x-2
	for (int i = 2; i < m; ++i) {
		for (int a = 0; a < 3; ++a) {
			for (int b = 0; b < 3; ++b) {
				int c0 = cou[i-2] - a - b;
				int c1 = cou[i-1] - b;
				int c2 = cou[i];
				int min_c = min(min(2, c0), min(c1, c2));

				for (int c = 0; c <= min_c; ++c) {
					dp[i+1][b][c] = max(dp[i+1][b][c], dp[i][a][b] + c + (c0 - c) / 3);
				}
			}
		}
	}
	int res = 0;
	for (int a = 0; a < 3; ++a) {
		for (int b = 0; b < 3; ++b) {
			int c0 = cou[m-2] - a - b;
			int c1 = cou[m-1] - b;
			res = max(res, c0 / 3 + c1 / 3 + dp[m][a][b]);
		}
	}
	cout << res << '\n';
}