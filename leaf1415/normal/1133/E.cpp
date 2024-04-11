#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int a[5005], r[5005];
int dp[5005][5005];

int main(void)
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++){
		r[i] = upper_bound(a+1, a+n+1, a[i]+5) - a - 1;
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= k; j++){
			dp[i][j] = -1e9;
		}
	}
	dp[0][0] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= k; j++){
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			if(j < k) dp[r[i+1]][j+1] = max(dp[r[i+1]][j+1], dp[i][j] + r[i+1]-i);
		}
	}
	
	int ans = 0;
	for(int i = 0; i <= k; i++) ans = max(ans, dp[n][i]);
	cout << ans << endl;
	
	return 0;
}