#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[2][5100][3]; // dp[i%2][k] i = chairs up to i, k = # of exposed path segments
// k = how many going right  (-1, 0, 1)
int main(){
	int n, s, e;
	cin >> n >> s >> e;
	LL x[n+1], a[n], b[n], c[n], d[n];
	for(int i = 0; i < n; i++) cin >> x[i];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0; i < n; i++) cin >> d[i];
	for(int j = 0; j < 5100; j++){
		for(int k = 0; k < 3; k++){
			dp[0][j][k] = 80000000000000000;
		}
	}
	x[n] = 0;
	dp[0][0][1] = 0;
	for(LL i = 0; i < n; i++){ //add 1-i%2
		LL dist = abs(x[i+1]-x[i]);
		//cout << dist << endl;
		for(LL j = 0; j < 5100; j++) for(int k = 0; k < 3; k++) dp[1-i%2][j][k] = 80000000000000000;
		for(LL j = 0; j <= 5000; j++){
			if(j == 0 && i > 0) continue;
			for(LL k = 0; k < 3; k++){
				if(dp[i%2][j][k] >= 80000000000000000) continue;
				//cout << i << " " << j << " " << k << " " << dp[i%2][j][k] << endl;
				if(i == s-1){
					if(k == 2) continue;
					dp[1-i%2][j+1][k+1] = min(dp[1-i%2][j+1][k+1],dp[i%2][j][k]+d[i] + (j+1)*dist); // makes new
					if(j > 0){
						dp[1-i%2][j-1][k+1] = min(dp[1-i%2][j-1][k+1],dp[i%2][j][k]+c[i]+ (j-1)*dist ); // removes old
					}
				} else if(i == e-1){
					if(k == 0) continue;
					dp[1-i%2][j+1][k-1] = min(dp[1-i%2][j+1][k-1],dp[i%2][j][k] + b[i]+ (j+1)*dist ); // makes new, land from right
					if(j > 0){
						dp[1-i%2][j-1][k-1] = min(dp[1-i%2][j-1][k-1],dp[i%2][j][k] + a[i]+ (j-1)*dist ); // lands from left, removes
					}
				} else {
					dp[1-i%2][j+2][k] = min(dp[1-i%2][j+2][k],dp[i%2][j][k]+b[i]+d[i] + (j+2)*dist );
					if(j >= 2){
						dp[1-i%2][j-2][k] = min(dp[1-i%2][j-2][k],dp[i%2][j][k]+a[i]+c[i]+(j-2)*dist );
					}
					if(j > 0 && (j > 1 || k != 0)){
						dp[1-i%2][j][k] = min(dp[1-i%2][j][k],dp[i%2][j][k]+a[i]+d[i] + (j)*dist );
					} 
					if(j > 0 && (j > 1 || k != 2)){
						dp[1-i%2][j][k] = min(dp[1-i%2][j][k],dp[i%2][j][k]+b[i]+c[i] + (j)*dist );
					} 
				}
			}
		}
	}
	cout << dp[n%2][0][1] << endl;
}