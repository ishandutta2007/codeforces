#include <iostream>
#define llint long long
#define mod 998244353

using namespace std;

llint n, m, k;
llint dp[2005][2005];

int main(void)
{
	cin >> n >> m >> k;
	
	dp[1][0] = m;
	for(int i = 1; i < n; i++){
		for(int j = 0; j <= k; j++){
			dp[i+1][j] += dp[i][j], dp[i+1][j] %= mod;
			if(j < k) dp[i+1][j+1] += dp[i][j] * (m-1) % mod, dp[i+1][j+1] %= mod;
		}
	}
	cout << dp[n][k] << endl;
	
	return 0;
}