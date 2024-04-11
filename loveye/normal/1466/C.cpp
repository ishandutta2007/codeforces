#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5,INF = 0x3f3f3f3f;
int n,T,dp[N][4];
char s[N];
int main() {
	cin >> T;
	while(T--) {
		cin >> s+1; n = strlen(s+1);
		dp[0][0] = 0;
		for(int i = 1;i <= n;++i) { 
			int p1 = s[i] == s[i-1],p2 = s[i] == s[i-2];
			dp[i][0] = min(p1 || p2 ? INF : dp[i-1][0],p1 ? INF : dp[i-1][2]);
			dp[i][1] = min(dp[i-1][2],dp[i-1][0]) + 1;
			dp[i][2] = min(p2 ? INF : dp[i-1][1],dp[i-1][3]);
			dp[i][3] = min(dp[i-1][1],dp[i-1][3]) + 1;
		}
		cout << min(min(dp[n][0],dp[n][1]),min(dp[n][2],dp[n][3])) << endl;
	}
	return 0;
}