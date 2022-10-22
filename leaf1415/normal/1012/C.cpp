#include <iostream>
#define llint long long
#define inf 1e18

using namespace std;

llint n;
llint a[5005];
llint dp[2][5005][2][2];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[0] = -inf;
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j <= (n+1)/2; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l < 2; l++){
					dp[i][j][k][l] = inf;
				}
			}
		}
	}
	dp[0][0][0][0] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= (n+1)/2; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l < 2; l++){
					dp[(i+1)%2][j][k][l] = inf;
				}
			}
		}
		for(int j = 0; j <= (n+1)/2; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l < 2; l++){
					if(k == 1){
						dp[(i+1)%2][j][0][1] = min(dp[(i+1)%2][j][0][1], dp[i%2][j][k][l] + max(0LL, a[i+1]-a[i]+1));
					}
					if(k == 0){
						dp[(i+1)%2][j][0][0] = min(dp[(i+1)%2][j][0][0], dp[i%2][j][k][l]);
						if(j == (n+1)/2) continue;
						if(l == 0){
							dp[(i+1)%2][j+1][1][0] = min(dp[(i+1)%2][j+1][1][0], dp[i%2][j][k][l] + max(0LL, a[i]-a[i+1]+1));
						}
						else if(l == 1 && i > 0){
							llint tmp = min(a[i], a[i-1]-1);
							dp[(i+1)%2][j+1][1][0] = min(dp[(i+1)%2][j+1][1][0], dp[i%2][j][k][l] + max(0LL, tmp-a[i+1]+1));
						}
					}
				}
			}
		}
	}
	
	for(int i = 1; i <= (n+1)/2; i++){
		llint ans = inf;
		for(int k = 0; k < 2; k++){
			for(int l = 0; l < 2; l++){
				ans = min(ans, dp[n%2][i][k][l]);
			}
		}
		cout << ans << " ";
	}
	cout << endl;
	
	return 0;
}