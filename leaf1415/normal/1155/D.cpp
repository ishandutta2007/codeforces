#include <iostream>
#define llint long long
#define inf 1e18+5

using namespace std;

llint n, x;
llint a[300005];
llint dp[300005][3][3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				dp[i][j][k] = -inf;
			}
		}
	}
	dp[0][0][0] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				
				for(int nj = j; nj <= min(2, j+1); nj++){
					for(int nk = k; nk <= min(2, k+1); nk++){
						if(nj == 1){
							if(nk == 1) dp[i+1][nj][nk] = max(dp[i+1][nj][nk], dp[i][j][k] + a[i+1]*x);
							else dp[i+1][nj][nk] = max(dp[i+1][nj][nk], dp[i][j][k] + a[i+1]);
						}
						else dp[i+1][nj][nk] = max(dp[i+1][nj][nk], dp[i][j][k]);
					}
				}
				
			}
		}
	}
	
	llint ans = 0;
	for(int j = 0; j < 3; j++){
		for(int k = 0; k < 3; k++){
			ans = max(ans, dp[n][j][k]);
		}
	}
	cout << ans << endl;
	
	return 0;
}