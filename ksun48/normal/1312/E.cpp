#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<int> > dp(n, vector<int>(n, -1));
	for(int j = 0; j < n; j++){
		for(int i = j; i >= 0; i--){
			if(i == j){
				dp[i][j] = a[i];
			} else {
				for(int k = i; k < j; k++){
					if(dp[i][k] == dp[k+1][j] && dp[i][k] != -1){
						dp[i][j] = max(dp[i][j], dp[i][k] + 1);
					}
				}
			}
		}
	}
	vector<int> best(n+1, 1e9);
	best[0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			if(dp[j][i-1] >= 0){
				best[i] = min(best[i], best[j] + 1);
			}
		}
	}
	cout << best[n] << '\n';
}