#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint n;
int dp[1000005][21][2];

int main(void)
{
	cin >> n;
	
	llint ans = 0, x = 0, y = 0;
	for(int t = 1; t*2 <= n; t*=2, x++);
	if(n >= 3){
		for(int t = 3; t*2 <= n; t*=2, y++);
	}
	
	dp[1][x][0] = n / (1<<x);
	if(y+1 == x) dp[1][y][1] = n / ((1<<y)*3);
	
	for(int i = 1; i < n; i++){
		llint rem, K;
		for(int j = 0; j <= 20; j++){
			for(int k = 0; k <= 1; k++){
				K = 1+k*2;
				rem = n / ((1<<j)*K) - i,
				(dp[i+1][j][k] += dp[i][j][k] * rem % mod) %= mod;
				if(j > 0){
					rem = n / ((1<<(j-1))*K) - n / ((1<<j)*K);
					(dp[i+1][j-1][k] += dp[i][j][k] * rem % mod) %= mod;
				}
				if(k > 0){
					rem = n / (1<<j) - n / ((1<<j)*K);
					(dp[i+1][j][k-1] += dp[i][j][k] * rem % mod) %= mod;
				}
			}
		}
	}
	
	cout << dp[n][0][0] << endl;
	return 0;
}