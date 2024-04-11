#include <cstdio>
#include <cstring>
typedef long long int LL;

LL sum, x, dp[105][2];

LL solve(int dep, int adv){
	if(dep < 0) return 1 - adv;
	if(dp[dep][adv] != -1) return dp[dep][adv];
	LL &cur = dp[dep][adv];
	if(x & (1LL << dep)){
		if(sum & (1LL << dep)){
			if(adv) return cur = 0LL;
			return cur = solve(dep - 1, 0) * 2LL;
		}else{
			if(adv) return cur = solve(dep - 1, 1) * 2LL;
			return cur = 0LL;
		}
	}else{
		if(sum & (1LL << dep)) return cur = solve(dep - 1, 1);
		return cur = solve(dep - 1, 0);
	}
}
int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%I64d%I64d", &sum, &x);
	printf("%I64d\n", solve(39, 0) - (sum == x ? 2LL : 0LL));
	return 0;
}