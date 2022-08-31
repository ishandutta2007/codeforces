#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[5100][2600][3];

const LL MAXN = 100000000000LL;
int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<LL> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int h = (n+1)/2;

	for(int i = 0; i < 5100; i++){
		for(int j = 0; j < h + 4; j++){
			for(int k = 0; k < 3; k++){
				dp[i][j][k] = MAXN;
			}
		}
	}
	dp[0][0][2] = 0;
	for(int i = 1; i <= n; i++){
		int b = i - 1;
		LL cost1 = 0;
		if(b > 0){
			LL v = a[b-1];
			if(b > 1) v = min(v, a[b-2] - 1);
			cost1 += max(0LL, v - (a[b] - 1) );
		}
		if(b + 1 < n){
			cost1 += max(0LL, a[b+1] - (a[b] - 1) );
		}
		LL cost2 = 0;
		if(b > 0){
			LL v = a[b-1];
			cost2 += max(0LL, v - (a[b] - 1) );
		}
		if(b + 1 < n){
			cost2 += max(0LL, a[b+1] - (a[b] - 1) );
		}
		for(int j = 0; j <= h; j++){
			dp[i][j][2] = min(dp[i][j][2], dp[i-1][j][2]);
			dp[i][j][2] = min(dp[i][j][2], dp[i-1][j][1]);
			dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][0]);
			dp[i][j+1][0] = min(dp[i][j+1][0], dp[i-1][j][1] + cost1);
			dp[i][j+1][0] = min(dp[i][j+1][0], dp[i-1][j][2] + cost2);
		}
	}
	for(int i = 1; i <= (n+1)/2; i++){
		LL ans = MAXN;
		for(int k = 0; k < 3; k++){
			ans = min(ans, dp[n][i][k]);
		}
		cout << ans << " ";
	}
	cout << endl;
}