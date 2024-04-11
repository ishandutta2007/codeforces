#include <iostream>
#include <string>
#define llint long long
#define inf 1e18

using namespace std;

llint n;
string s;
llint a[100005];
llint dp[100005][5];

int main(void)
{
	cin >> n;
	cin >> s;
	s = "#" + s;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 4; j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 4; j++){
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]+a[i+1]);
			if(j == 0){
				if(s[i+1] == 'h') dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
				else dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			}
			if(j == 1){
				if(s[i+1] == 'a') dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
				else dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			}
			if(j == 2){
				if(s[i+1] == 'r') dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
				else dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			}
			if(j == 3){
				if(s[i+1] == 'd');
				else dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			}
		}
	}
	
	llint ans = inf;
	for(int i = 0; i < 4; i++) ans = min(ans, dp[n][i]);
	cout << ans << endl;
	
	return 0;
}