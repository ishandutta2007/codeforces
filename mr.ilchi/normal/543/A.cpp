#include <bits/stdc++.h>
using namespace std;

int a[505];
int dp[505][505];

int main(){
	int n,m,b,mod; cin >> n >> m >> b >> mod;
	for (int i=0; i<n; i++)
		cin >> a[i];
	dp[0][0] = 1 % mod;
	for (int i=0; i<n; i++){
		for (int j=1; j<=m; j++)
			for (int k=a[i]; k<=b; k++){
				dp[j][k]+= dp[j-1][k-a[i]];
				if (dp[j][k] >= mod)
					dp[j][k]-= mod;
			}
	}
	int ans = 0;
	for (int i=0; i<=b; i++)
		ans = (ans + dp[m][i]) % mod;
	cout << ans << endl;
	return 0;
}