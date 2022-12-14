#include <cstdio>
#define MOD 1000000007
#define MAX 1005

int dp[MAX], n, p[MAX];

int main(){
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &p[i]);
	for(i = 1; i <= n; ++ i)
		dp[i] = (((dp[i - 1] + (dp[i - 1] - dp[p[i] - 1] + i - p[i] + 1) % MOD) % MOD) + MOD) % MOD;
	printf("%d\n", (dp[n] + n) % MOD);
	return 0;
}