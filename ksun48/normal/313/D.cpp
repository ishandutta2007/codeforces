#include<iostream>

using namespace std;

#define LL long long

LL mincost[301][301];
LL dp[301][301]; // dp[i][j] = min cost for first i holes, to fix j holes
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < 301; i++){
		for(int j = 0; j < 301; j++){
			dp[i][j] = mincost[i][j] = 400000000000;
		}
	}
	for(int i = 0; i < m; i++){
		int l, r;
		LL c;
		cin >> l >> r >> c;
		mincost[l][r] = min(mincost[l][r], c);
	}
	for(int i = 1; i < 301; i++){
		for(int j = 0; j < 301; j++){
			mincost[i][j] = min(mincost[i][j], mincost[i-1][j]);
		}
	}
	for(int i = 0; i < 301; i++){
		dp[i][0] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = min(dp[i][j], dp[i-1][j]);
			for(int k = 0; k < i; k++){
				dp[i][j] = min(dp[i][j], dp[k][max(0,j-(i-k))]+mincost[k+1][i]);
			}
		}
	}
	LL ans = 400000000000;
	ans = min(ans, dp[n][k]);
	if(ans >= 400000000000){
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}