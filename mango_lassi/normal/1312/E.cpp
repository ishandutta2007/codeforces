#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 500;
int can[N][N];
int dp[N+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> can[i][i];
	for (int len = 2; len <= n; ++len) {
		for (int i = 0; i + len <= n; ++i) {
			int t = i + len - 1;
			for (int j = i; j < t; ++j) {
				if (can[i][j] && can[i][j] == can[j+1][t]) can[i][t] = can[i][j] + 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		dp[i+1] = n;
		for (int j = 0; j <= i; ++j) {
			if (can[j][i]) dp[i+1] = min(dp[i+1], dp[j] + 1);
		}
	}
	cout << dp[n] << '\n';
}