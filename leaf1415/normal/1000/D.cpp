#include <iostream>
#define llint long long
#define mod 998244353

using namespace std;

llint n;
llint a[1005];
llint dp[1005][1005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= n; j++){
			if(j > 0){
				dp[i+1][j-1] += dp[i][j];
				dp[i+1][j-1] %= mod;
			}
			else{
				if(a[i+1] > 0 && a[i+1] <= n){
					dp[i+1][a[i+1]] += dp[i][j];
					dp[i+1][a[i+1]] %= mod;
				}
			}
			dp[i+1][j] += dp[i][j];
			dp[i+1][j] %= mod;
		}
	}
	
	cout << dp[n][0]-1 << endl;
	return 0;
}