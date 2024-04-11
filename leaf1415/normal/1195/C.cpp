#include <iostream>
#define llint long long

using namespace std;

llint n;
llint h[100005][2];
llint dp[100005][3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> h[i][0];
	for(int i = 1; i <= n; i++) cin >> h[i][1];
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 3; j++){
			dp[i][j] = -1e18;
		}
	}
	dp[0][2] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				if(k != 2 && j == k) continue;
				llint add = 0;
				if(k != 2) add = h[i+1][k];
				dp[i+1][k] = max(dp[i+1][k], dp[i][j] + add);
			}
		}
	}
	llint ans = 0;
	for(int i = 0; i < 3; i++) ans = max(ans, dp[n][i]);
	cout << ans << endl;
	
	return 0;
}