#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn = 5010, maxa = 1e5 + 10;
int dp[maxn][maxn],n,a[maxn],m7[7],d[maxa],ans;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	
	for(int i = 0; i <= n; ++i){
		memset(m7, 0, sizeof m7);
		memset(d, 0, sizeof d);
		for(int j = 1; j < i; ++j)
			m7[a[j] % 7] = max(m7[a[j] % 7], dp[i][j]),
			d[a[j]] = max(d[a[j]], dp[i][j]);
		
		for(int j = i + 1; j <= n; ++j)
			dp[i][j] = max(max(m7[a[j] % 7], dp[i][0]), max(d[a[j] + 1], d[a[j] - 1])) + 1,
			dp[j][i] = dp[i][j],
			m7[a[j] % 7] = max(m7[a[j] % 7], dp[i][j]),
			d[a[j]] = max(d[a[j]], dp[i][j]),
			ans = max(ans, dp[i][j]);
	}
	
	printf("%d", ans);
	
	return 0;
}