#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// Trivial if not for that one
// DP[2^n][a]

const ll INF = 1e18;
const int N = 16;
const int M = 1e4;
const int H = 1<<N;
ll cost[N][N];
ll loop[N][N];
ll arr[N][M];
ll dp[1<<N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int h = 1 << n;

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) cin >> arr[y][x];
	}

	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			ll res = INF;
			for (int x = 0; x < m; ++x) {
				res = min(res, abs(arr[a][x] - arr[b][x]));
			}
			cost[a][b] = res;

			res = INF;
			for (int x = 0; x+1 < m; ++x) {
				res = min(res, abs(arr[a][x] - arr[b][x+1]));
			}
			loop[a][b] = res;
		}
	}

	ll ans = 0;
	for (int s = 0; s < n; ++s) {
		int ini = 1 << s;
		for (int i = 0; i < h; ++i) {
			for (int b = 0; b < n; ++b) {
				dp[i][b] = 0;
			}
		}
		dp[ini][s] = INF;

		for (int mask = 1; mask < h; ++mask) {
			if ((mask & ini) == 0) continue;
			if (mask + 1 == h) continue;
			for (int a = 0; a < n; ++a) {
				if (dp[mask][a] == 0) continue;
				for (int b = 0; b < n; ++b) {
					int bbit = 1 << b;
					if (mask & bbit) continue;

					int t = mask | bbit;
					dp[t][b] = max(dp[t][b], min(dp[mask][a], cost[a][b]));
				}
			}
		}

		int full = h-1;
		for (int b = 0; b < n; ++b) {
			ans = max(ans, min(dp[full][b], loop[b][s]));
		}
	}
	cout << ans << '\n';
}