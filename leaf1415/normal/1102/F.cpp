#include <iostream>
#include <stdlib.h>
#define llint long long
#define inf 1e18

using namespace std;

llint n, m;
llint a[16][10005];
llint dif[16][16], dif2[16][16];
llint dp[1<<16][16];

int main(void)
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			llint mn = inf;
			for(int k = 0; k < m; k++){
				mn = min(mn, abs(a[j][k] - a[i][k]));
			}
			dif[i][j] = mn;
			
			mn = inf;
			for(int k = 0; k < m-1; k++){
				mn = min(mn, abs(a[j][k+1] - a[i][k]));
			}
			dif2[i][j] = mn;
		}
	}
	
	int S = 1 << n;
	
	llint ans = -inf;
	for(int i = 0; i < n; i++){
		
		for(int j = 0; j < S; j++){
			for(int k = 0; k < n; k++) dp[j][k] = -inf;
		}
		dp[1<<i][i] = inf;
		
		for(int j = 0; j < S; j++){
			for(int k = 0; k < n; k++){
				for(int l = 0; l < n; l++){
					if(j & (1<<l)) continue;
					int nj = j | 1<<l;
					dp[nj][l] = max(dp[nj][l], min(dp[j][k], dif[k][l]));
				}
			}
		}
		for(int j = 0; j < n; j++){
			ans = max(ans, min(dp[S-1][j], dif2[j][i]));
		}
	}
	cout << ans << endl;
	
	return 0;
}