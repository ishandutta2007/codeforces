#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n,m;
int a[205];
int dp[2][205][1007];

void add(int &x,int y) {
	x += y; while(x >= mod) x -= mod; while(x < 0) x += mod;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;++i) scanf("%d",&a[i]);
	sort(a + 1,a + 1 + n);
	dp[0][0][0] = 1;
	for(int i = 0;i < n;++i) {
		for(int j = 0;j <= n;++j) 
			for(int k = 0;k <= m;++k) dp[i & 1 ^ 1][j][k] = 0;
		for(int j = 0;j <= n;++j) {
			for(int k = 0;k <= m;++k) {
				int nxt = k + j * (a[i + 1] - a[i]);
				if(nxt > m) continue;
				add(dp[i & 1 ^ 1][j][nxt],(1LL * (j + 1) * dp[i & 1][j][k]) % mod);
				if(j) add(dp[i & 1 ^ 1][j - 1][nxt],(1LL * j * dp[i & 1][j][k]) % mod);
				if(n - j) add(dp[i & 1 ^ 1][j + 1][nxt],dp[i & 1][j][k]);
			}   	
		}
	}
	int ans = 0;
	for(int i = 0;i <= m;++i) add(ans,dp[n & 1][0][i]);
	cout << ans << endl;
}