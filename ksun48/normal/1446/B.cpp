#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = max(dp[i][j], dp[i-1][j] - 1);
			dp[i][j] = max(dp[i][j], dp[i][j-1] - 1);
			if(s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 2);
		}
	}
	int best = 0;
	for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) best = max(best, dp[i][j]);
	cout << best << '\n';
}