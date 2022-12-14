#include <cstdio>
const int MAXN = 1005, MOD = 1000000007;

int n, f[MAXN];

int main(){
	int i, j, t, ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &t), f[i] = 1;
		for(j = t; j < i; ++ j)
			f[i] = (f[i] + f[j] + 1) % MOD;
		ans = (ans + f[i] + 1) % MOD;
	} printf("%d\n", ans);
	return 0;
}