#include <iostream>
#define llint long long
#define mod 998244353

using namespace std;

llint n, k;
llint dp[1005][2005][4];

int main(void)
{
	cin >> n >> k;
	
	dp[1][1][0] = dp[1][1][3] = 1;
	dp[1][2][1] = dp[1][2][2] = 1;
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j <= k; j++){
			for(int k = 0; k < 4; k++){
				if(k == 3) dp[i+1][j+1][0] += dp[i][j][k], dp[i+1][j+1][0] %= mod;
				else dp[i+1][j][0] += dp[i][j][k], dp[i+1][j][0] %= mod; 
				
				if(k == 0) dp[i+1][j+1][3] += dp[i][j][k], dp[i+1][j+1][3] %= mod;
				else dp[i+1][j][3] += dp[i][j][k], dp[i+1][j][3] %= mod; 
				
				if(k == 2) dp[i+1][j+2][1] += dp[i][j][k], dp[i+1][j+2][1] %= mod;
				else if(k == 1) dp[i+1][j][1] += dp[i][j][k], dp[i+1][j][1] %= mod;
				else dp[i+1][j+1][1] += dp[i][j][k], dp[i+1][j+1][1] %= mod; 
				
				if(k == 1) dp[i+1][j+2][2] += dp[i][j][k], dp[i+1][j+2][2] %= mod;
				else if(k == 2) dp[i+1][j][2] += dp[i][j][k], dp[i+1][j][2] %= mod;
				else dp[i+1][j+1][2] += dp[i][j][k], dp[i+1][j+1][2] %= mod; 
			}
		}
	}
	
	llint ans = 0;
	for(int i = 0; i < 4; i++) ans += dp[n][k][i], ans %= mod;
	cout << ans << endl;
	
	return 0;
}