#include <iostream>
using namespace std;

const int INF = 1e9;
const int N = 50;
const int K = 2000;
const int R = 50;
int dp[N][K+1];
int val[N];

int main() {
	int n, s, k;
	cin >> n >> s >> k;
	--s;

	for (int i = 0; i < n; ++i) cin >> val[i];

	string col;
	cin >> col;

	// O(n^2 k)
	for (int r = R; r > 0; --r) {
		for (int i = 0; i < n; ++i) {
			if (val[i] == r) {
				for (int v = val[i] + 1; v <= k; ++v) dp[i][v] = INF;
				for (int t = 0; t < n; ++t) {
					if (val[t] > val[i] && col[t] != col[i]) {
						int dist = abs(t - i);
						for (int v = 0; v + val[i] <= k; ++v) {
							dp[i][v + val[i]] = min(dp[i][v + val[i]], dist + dp[t][v]);
						}
					}
				}
			}
		}
	}

	int res = INF;
	for (int t = 0; t < n; ++t) res = min(res, dp[t][k] + abs(t - s));
	if (res == INF) res = -1;
	cout << res << '\n';
}