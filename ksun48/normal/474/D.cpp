#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T, k;
	cin >> T >> k;
	const int MOD = int(1e9) + 7;
	const int MAXN = int(1e5) + 10;
	vector<int> dp(MAXN, 0);
	dp[0] = 1;
	for(int j = 1; j < MAXN; j++){
		dp[j] += dp[j-1];
		if(j >= k) dp[j] += dp[j-k];
		dp[j] %= MOD;
	}
	for(int j = 1; j < MAXN; j++){
		dp[j] += dp[j-1];
		dp[j] %= MOD;
	}
	for(int t = 0; t < T; t++){
		int a, b;
		cin >> a >> b;
		int ans = dp[b] - dp[a-1];
		while(ans < 0) ans += MOD;
		ans %= MOD;
		cout << ans << '\n';
	}
}