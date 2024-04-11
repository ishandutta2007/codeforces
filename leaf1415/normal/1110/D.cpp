#include <iostream>

using namespace std;

int n, m;
int cnt[1000005];
int dp[1000005][3][3];

int main(void)
{
	cin >> n >> m;
	int a;
	for(int i = 1; i <= n; i++){
		cin >> a;
		cnt[a]++;
	}
	
	for(int i = 0; i <= m; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				dp[i][j][k] = -1e9;
			}
		}
	}
	dp[0][0][0] = 0;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				for(int l = 0; l < 3; l++){
					if(cnt[i+1]-(j+k+l) < 0) continue;
					if(cnt[i+2]-(k+l) < 0) continue;
					if(cnt[i+3]-l < 0) continue;
					dp[i+1][k][l] = max(dp[i+1][k][l], dp[i][j][k] + (cnt[i+1]-(j+k+l))/3 + l);
				}
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			ans = max(ans, dp[m][i][j]);
		}
	}
	cout << ans << endl;
	
	return 0;
}