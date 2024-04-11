#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
const int N = 17 - 1;
bool fan[1<<(N+1)];
int dp[N][1<<N][4];
ll conns[4][4][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int a = 0; a < 4; ++a) {
		for (int b = 0; b < 4; ++b) {
			int up = (a & 1) + (b & 1);
			int dn = ((a & 2) + (b & 2)) / 2;

			conns[a][b][0] = 0;
			conns[a][b][1] = (up ? 1 : -INF);
			conns[a][b][2] = ((up || dn) ? 2 : -INF);
			conns[a][b][3] = ((up == 2 || (up && dn)) ? 2 + (dn > 0) : -INF);
		}
	}

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		int j;
		cin >> j;
		fan[j-1] = 1;
	}

	for (int i = 0; i < (1 << (n-1)); ++i) {
		if (fan[2*i] && fan[2*i+1]) dp[0][i][3] = 1;
		else dp[0][i][3] = -INF;

		if (fan[2*i] || fan[2*i+1]) {
			dp[0][i][1] = 1;
			dp[0][i][2] = 1;
		} else {
			dp[0][i][1] = -INF;
			dp[0][i][2] = -INF;
		}

		// cerr << 0 << ' ' << i << ": " << dp[0][i][0] << ' ' << dp[0][i][1] << ' ' << dp[0][i][2] << ' ' << dp[0][i][3] << '\n';
	}
	for (int j = 1; j < n; ++j) {
		for (int i = 0; i < (1 << (n-1-j)); ++i) {
			for (int c = 0; c < 4; ++c) {
				ll ans = -INF;
				for (int a = 0; a < 4; ++a) {
					for (int b = 0; b < 4; ++b) {
						ll off = conns[a][b][c] + (ll)dp[j-1][2*i][a] + (ll)dp[j-1][2*i+1][b];
						if (off <= -INF) off = -INF;
						ans = max(ans, off);
					}
				}
				dp[j][i][c] = ans;
			}
			// cerr << j << ' ' << i << ": " << dp[j][i][0] << ' ' << dp[j][i][1] << ' ' << dp[j][i][2] << ' ' << dp[j][i][3] << '\n';
		}
	}

	int res = 0;
	for (int a = 0; a < 4; ++a) {
		res = max(res, dp[n-1][0][a] + (a != 0));
	}
	cout << res << '\n';
}