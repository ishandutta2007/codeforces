#include <iostream>
#include <cstdlib>
#define llint long long
#define inf 1e18

using namespace std;

llint n;
llint p[105];
llint dp[105][105][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i];
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n/2; j++){
			for(int k = 0; k < 2; k++){
				dp[i][j][k] = inf;
			}
		}
	}
	dp[0][0][0] = dp[0][0][1] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= n/2; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l < 2; l++){
					if(p[i+1] != 0 && p[i+1]%2 != l) continue;
					if(j+(1-l) <= n/2) dp[i+1][j+(1-l)][l] = min(dp[i+1][j+(1-l)][l], dp[i][j][k] + abs(k-l));
				}
			}
		}
	}
	cout << min(dp[n][n/2][0], dp[n][n/2][1]) << endl;
	
	return 0;
}