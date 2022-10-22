#include <iostream>
#define llint long long
#define mod 998244353

using namespace std;

llint n;
llint a[200005];
llint dp[2][205][2];
llint sum[205][2];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	if(a[1] != -1){
		dp[1][a[1]][1] = 1;
	}
	else{
		for(int j = 1; j <= 200; j++) dp[1][j][1] = 1;
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= 200; j++){
			for(int k = 0; k < 2; k++){
				sum[j][k] = sum[j-1][k] + dp[(i+1)%2][j][k];
				sum[j][k] %= mod;
			}
		}
		for(int j = 1; j <= 200; j++){
			dp[i%2][j][0] = dp[i%2][j][1] = 0;
			
			dp[i%2][j][0] += sum[200][0] - sum[j-1][0] + mod;
			dp[i%2][j][0] %= mod;
			dp[i%2][j][1] += sum[j-1][0];
			dp[i%2][j][1] %= mod;
			
			dp[i%2][j][0] += sum[j][1] - sum[j-1][1] + mod;
			dp[i%2][j][0] %= mod;
			dp[i%2][j][1] += sum[j-1][1];
			dp[i%2][j][1] %= mod;
		}
		if(a[i] != -1){
			for(int j = 1; j <= 200; j++){
				if(a[i] != j) dp[i%2][j][0] = dp[i%2][j][1] = 0;
			}
		}
	}
	
	/*for(int i = 0; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			for(int k = 0; k < 2; k++){
				cout << dp[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}*/
	
	llint ans = 0;
	for(int j = 1; j <= 200; j++) ans += dp[n%2][j][0], ans %= mod;
	cout << ans << endl;
	
	return 0;
}