#include <cstdio>
typedef long long int LL;
const LL MOD = 1000000007LL;

int p, k; bool vis[1000005];

int quickPow(int times){
	LL ret = 1LL, base = p;
	while(times){
		if(times & 1) ret = (ret * base) % MOD;
		base = (base * base) % MOD;
		times >>= 1;
	}
	return int(ret);
}
int main(){
	int i, j, ans = 0;
	scanf("%d%d", &p, &k);
	if(k == 0){
		printf("%d\n", quickPow(p - 1));
		return 0;
	}
	if(k == 1){
		printf("%d\n", quickPow(p));
		return 0;
	}
	for(i = 1; i < p; ++ i){
		if(vis[i]) continue;
		for(++ ans, j = i; !vis[j]; j = (LL(j) * k) % p)
			vis[j] = true;
	}
	printf("%d\n", quickPow(ans));
	return 0;
}