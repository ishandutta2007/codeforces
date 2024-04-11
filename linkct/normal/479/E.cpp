#include <cstdio>
#define MAXN 5005
#define MOD 1000000007

int dp[2][MAXN], f[2][MAXN], n, a, b, k;

int main(){
	int i, j, now = 1;
	scanf("%d%d%d%d", &n, &a, &b, &k);
	if(a < b) n = b - 1, a = b - a;
	else n -= b, a -= b;
	dp[0][a] = 1;
	for(i = 1; i < a; ++ i) f[0][i] = 0;
	for(; i <= n; ++ i) f[0][i] = 1;
	for(i = 1; i <= k; ++ i){
		for(j = 1; j <= n; ++ j){
			dp[now][j] = ((f[now ^ 1][n] - f[now ^ 1][j / 2] - dp[now ^ 1][j]) % MOD + MOD) % MOD;
			f[now][j] = (f[now][j - 1] + dp[now][j]) % MOD;
		}
		now ^= 1;
	}
	printf("%d\n", f[now ^ 1][n]);
	return 0;
}