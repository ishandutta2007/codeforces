#include <bits/stdc++.h>
using namespace std;

string S[2000];
int n,m,a,dp[2000][2000] = {};

signed main() {
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> S[i];
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
		dp[i][j] = 1;
		if (i>1 && j>0 && j<m-1 && S[i][j] == S[i-1][j-1] && S[i][j] == S[i-1][j] && S[i][j] == S[i-1][j+1] && S[i][j] == S[i-2][j])
			dp[i][j] = min({dp[i-1][j-1], dp[i-2][j], dp[i-1][j+1]}) + 1;
		a += dp[i][j];
	}
	cout << a << endl;
	return 0;
}