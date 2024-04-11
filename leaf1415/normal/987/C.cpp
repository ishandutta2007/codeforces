#include <iostream>
#define inf 1e9

using namespace std;

int n;
int s[3005];
int c[3005];
int dp[3005][4][3005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= 3; j++){
			for(int k = 0; k <= n; k++){
				dp[i][j][k] = inf;
			}
		}
	}
	dp[0][0][0] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= 3; j++){
			for(int k = 0; k <= i; k++){
				dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
				if(j < 3 && s[i+1] > s[k]) dp[i+1][j+1][i+1] = min(dp[i+1][j+1][i+1], dp[i][j][k] + c[i+1]);
			}
		}
	}
	
	int ans = inf;
	for(int i = 1; i <= n; i++) ans = min(ans, dp[n][3][i]);
	if(ans >= inf) ans = -1;
	
	cout << ans << endl;
	return 0;
}