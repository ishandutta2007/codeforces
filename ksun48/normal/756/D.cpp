#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
int dp[5001][26];

int main(){
	int n;
	cin >> n;
	string d;
	cin >> d;
	int sum[n+1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 26; j++){
			dp[i][j] = 0;
		}
		sum[i] = 0;
	}
	for(int i = 0; i < n; i++){
		int a = d[i]-'a';
		sum[1] = sum[1] + (MOD - dp[1][a] + 1);
		sum[1] %= MOD;
		dp[1][a] = 1;
		for(int f = 2; f <= n; f++){
			sum[f] = sum[f] + (MOD - dp[f][a]);
			sum[f] %= MOD;
			dp[f][a] = sum[f-1] % MOD;
			sum[f] += dp[f][a];
			sum[f] %= MOD;
		}
	}
	int ans = sum[n] % MOD;
	cout << ans << endl;
}