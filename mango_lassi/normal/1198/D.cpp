#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 50;
string dat[N];
int cou[N+1][N+1];
int dp[N][N][N][N];

int calc(int y0, int y1, int x0, int x1) {
	return cou[y1+1][x1+1] - cou[y0][x1+1] - cou[y1+1][x0] + cou[y0][x0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int y = 0; y < n; ++y) {
		cin >> dat[y];
		for (int x = 0; x < n; ++x) {
			cou[y+1][x+1] = (dat[y][x] == '#');
		}
	}
	for (int y = 1; y <= n; ++y) {
		for (int x = 1; x <= n; ++x) {
			cou[y][x] += cou[y-1][x] + cou[y][x-1] - cou[y-1][x-1];
		}
	}

	// To achieve a solution better than n, we do not paint some row and some column.
	// Divide and conquer: DP[a][b][c][d]: cost to color rectangle [a, b] x [c, d]

	for (int h = 0; h < n; ++h) {
		for (int w = 0; w < n; ++w) {
			for (int y0 = 0; y0+h < n; ++y0) {
				int y1 = y0 + h;
				for (int x0 = 0; x0+w < n; ++x0) {
					int x1 = x0 + w;

					int res = max(h+1, w+1);
					for (int i = y0; i <= y1; ++i) {
						if (calc(i, i, x0, x1) == 0) {
							int off = 0;
							if (i > y0) off += dp[y0][i-1][x0][x1];
							if (i < y1) off += dp[i+1][y1][x0][x1];
							res = min(res, off);
						}
					}
					for (int i = x0; i <= x1; ++i) {
						if (calc(y0, y1, i, i) == 0) {
							int off = 0;
							if (i > x0) off += dp[y0][y1][x0][i-1];
							if (i < x1) off += dp[y0][y1][i+1][x1];
							res = min(res, off);
						}
					}
					dp[y0][y1][x0][x1] = res;
					// cout << y0 << ' ' << y1 << ' ' << x0 << ' ' << x1 << ": " << res << '\n';
				}
			}
		}
	}
	cout << dp[0][n-1][0][n-1] << '\n';
}