#include <iostream>
#include <string>
#define llint long long
#define inf 1e18

using namespace std;

llint n;
llint c[1005], v[1005];
llint dp[1005][8];

int main(void)
{
	cin >> n;
	
	string s;
	for(int i = 1; i <= n; i++){
		cin >> c[i] >> s;
		for(int j = 0; j < s.size(); j++){
			if(s[j] == 'A') v[i] += 1;
			if(s[j] == 'B') v[i] += 2;
			if(s[j] == 'C') v[i] += 4;
		}
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 8; j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 8; j++){
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			dp[i+1][j|v[i+1]] = min(dp[i+1][j|v[i+1]], dp[i][j] + c[i+1]);
		}
	}
	
	llint ans = dp[n][7];
	if(ans >= inf) ans = -1;
	cout << ans << endl;
	
	return 0;
}