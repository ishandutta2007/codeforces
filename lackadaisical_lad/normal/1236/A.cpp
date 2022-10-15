//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int N = 105;

int dp[N][N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (i >= 1 && j >= 2) {
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 2][k] + 3);
				}
				if (j >= 1 && k >= 2) {
					dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 2] + 3);
				}
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << dp[a][b][c] << endl;
	}
    return 0;
}