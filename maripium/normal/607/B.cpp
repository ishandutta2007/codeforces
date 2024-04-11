#include<bits/stdc++.h>
using namespace std;

const int N = 505;

int n;
int a[N];
int dp[N][N];

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) for(int j = 1;j <= n;++j) dp[i][j] = 1e9;
	for(int i = 1;i <= n;++i) cin >> a[i];
	for(int i = 1;i <= n;++i) dp[i][i] = 1;
	for(int i = 1;i < n;++i) dp[i][i + 1] = 1 + (a[i] != a[i + 1]);
	for(int i = 3;i <= n;++i) {
		for(int j = 1;j + i <= n + 1;++j) {
			int k = j + i - 1;
			if(a[j] == a[k]) dp[j][k] = dp[j + 1][k - 1];
			for(int l = j; l < k; ++l) dp[j][k] = min(dp[j][k],dp[j][l] + dp[l + 1][k]);
		}
	}
	cout << dp[1][n] << endl;
}