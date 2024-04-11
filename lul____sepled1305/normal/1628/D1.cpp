#include <bits/stdc++.h>
using namespace std;
const int mod =1e9+7;

int add(int a,int b) {
	return (a+b)%mod;
}

int mul(int a,int b) {
	long long g = (1LL*a*b)%mod;
	return (int) g;
}

int power(int b, int p) {
	if(p == 0)
		return 1;
	
	int g = power(b,p/2);
	g = mul(g,g);
	if(p%2) g = mul(g,b);
	return g;
}

int main() {
	// your code goes here
	int T; cin>>T;
	int inv = power(2,mod-2);
	while(T--) {
		int n,m,k; cin>>n>>m>>k;
		int dp[n+1][m+1];
		for(int i=0;i<=n;i++) {
			for(int j=0;j<=m;j++) {
				if(i == 0) {
					dp[i][j] = 0;
					continue;
				}
				if(j == 0) {
					dp[i][j] = dp[i-1][j];
					continue;
				}
				if(j > i) {
					dp[i][j] = 0;
					continue;
				}
				if(j == i) {
					dp[i][j] = mul(k,i);
					continue;
				}
				dp[i][j] = add(dp[i-1][j], dp[i-1][j-1]);
				dp[i][j] = mul(dp[i][j],inv);
			}
		}
		cout<<dp[n][m]<<'\n';
	}
	return 0;
}