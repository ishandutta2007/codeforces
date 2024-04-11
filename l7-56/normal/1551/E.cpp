#include<bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int a[maxn],dp[maxn][maxn],n,k,t;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
			for(int j = 0; j <= n; ++j){
				dp[i][j] = dp[i - 1][j] + (a[i] == i - j);
				if(j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
			}
		}
		int ans = -1;
		for(int j = 0; j <= n; j++)
			if(dp[n][j] >= k) {ans = j; break;}
		printf("%d\n", ans);
	}
	return 0;
}