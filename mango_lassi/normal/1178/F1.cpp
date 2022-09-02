#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

const int N = 501;
ll dp[N][N];
int col[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// DP[a][b]: Ways to color interval [a, b] with colors appearing in it
	int n, unused;
	cin >> n >> unused;

	for (int i = 0; i < n; ++i) {
		cin >> col[i];
		--col[i];
	}
	for (int i = 0; i < n; ++i) dp[i][i] = 1;
	for (int k = 2; k <= n; ++k) {
		for (int a = 0; a+k <= n; ++a) {
			int b = a+k-1;

			int j = a;
			for (int i = a; i <= b; ++i) {
				if (col[i] < col[j]) j = i;
			}
			ll lefts = 0;
			for (int x = a; x <= j; ++x) {
				ll add = 1;
				if (x < j) add = (add * dp[x][j-1]) % MOD;
				if (a < x) add = (add * dp[a][x-1]) % MOD;
				lefts = (lefts + add) % MOD;
			}
			ll rights = 0;
			for (int y = j; y <= b; ++y) {
				ll add = 1;
				if (j < y) add = (add * dp[j+1][y]) % MOD;
				if (y < b) add = (add * dp[y+1][b]) % MOD;
				rights = (rights + add) % MOD;
			}
			dp[a][b] = (lefts * rights) % MOD;
		}
	}
	cout << dp[0][n-1] << '\n';
}