#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3 * (int)1e3;

int dp[N][N][2];

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) cin >> a;
	
	vector<int> nxt(n, n), pre(n, -1);
	for (int i = 0; i < n; ++i) {
		for (int j = i-1; j >= 0; --j) {
			if (as[j] == as[i]) {
				pre[i] = j;
				break;
			}
		}
		for (int j = i + 1; j < n; ++j) {
			if (as[j] == as[i]) {
				nxt[i] = j;
				break;
			}
		}
	}

	for (int b = 0; b < n; ++b) {
		for (int a = b - 1; a >= 0; --a) {
			if (as[a] == as[b]) {
				int v = min(dp[a][b-1][0], dp[a+1][b][1]);
				dp[a][b][0] = v;
				dp[a][b][1] = v;
			} else {
				dp[a][b][0] = dp[a + 1][b][1] + 1;
				for (int x = nxt[a]; x <= b; x = nxt[x]) {
					dp[a][b][0] = min(dp[a][b][0], dp[a][x][1] + dp[x][b][0]);
				}

				dp[a][b][1] = dp[a][b - 1][0] + 1;
				for (int x = pre[b]; x >= a; x = pre[x]) {
					dp[a][b][1] = min(dp[a][b][1], dp[a][x][1] + dp[x][b][0]);
				}
			}
		}
	}
	cout << min(dp[0][n-1][0], dp[0][n-1][1]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}