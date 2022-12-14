#include <cstdio>
#define MAXN 100005
#define MOD 1000000007

int dp[MAXN], q, k, pf[MAXN];
//dp[i][0]: the end of a white section

void Dp(){
	for(int i = 1; i <= k; ++ i)
		dp[i] = 1, pf[i] = i;
	dp[k] ++, pf[k] ++;
	for(int i = k + 1; i <= 100000; ++ i){
		dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
		pf[i] = (pf[i - 1] + dp[i]) % MOD;
	}
}
int main(){
	int i, a, b;
	scanf("%d%d", &q, &k);
	Dp();
	for(i = 1; i <= q; ++ i){
		scanf("%d%d", &a, &b);
		printf("%d\n", (pf[b] - pf[a - 1] + MOD) % MOD);
	}
	return 0;
}