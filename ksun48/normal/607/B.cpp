#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int dp[n][n]; // i -> j
	for(int i = 0; i < n; i++){
		for(int j = 0; j + i < n; j++){
			int k = j + i; // i -> k
			dp[j][k] = 10000;
			if(j == k){
				dp[j][k] = 1;
				continue;
			}
			for(int c = j; c < k; c++){
				dp[j][k] = min(dp[j][k], dp[j][c] + dp[c+1][k]);
			}
			if(a[j] == a[k]){
				if(j + 1 == k){
					dp[j][k] = 1;
					continue;
				}
				dp[j][k] = min(dp[j][k], dp[j+1][k-1]);
			}
		}
	}
	cout << dp[0][n-1] << endl;
}