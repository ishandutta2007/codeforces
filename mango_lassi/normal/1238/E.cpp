#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e18 + 7;

const int M = 20;
int cou[M][M];
ll dp[1<<M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < (1<<m); ++i) dp[i] = INF;

	string str;
	cin >> str;
	for (int i = 0; i+1 < n; ++i) {
		int x = str[i] - 'a';
		int y = str[i+1] - 'a';
		++cou[x][y];
		++cou[y][x];
	}

	dp[0] = 0;
	for (int i = 0; i < (1<<m); ++i) {
		ll off = dp[i];
		for (int j = 0; j < m; ++j) {
			if (i & (1<<j)) continue;
			for (int t = 0; t < m; ++t) {
				if (i & (1<<t)) off += cou[j][t];
			}
		}
		for (int j = 0; j < m; ++j) {
			dp[i | (1<<j)] = min(dp[i | (1<<j)], off);
		}
	}
	cout << dp[(1 << m) - 1] << '\n';
}