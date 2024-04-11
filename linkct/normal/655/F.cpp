#include <cstdio>
typedef long long int LL;
const int MAXN = 200005, MAXV = 1000005;
const LL MOD = 1000000007LL;

int cnt[MAXV], n, k, q, phi[MAXV], prime[MAXV], pcnt;
LL ans, f[MAXN], inv[MAXN];

void preCalc(){
	int i, j; phi[1] = 1;
	for(i = 2; i < MAXV; ++ i){
		if(!phi[i]){
			prime[++ pcnt] = i;
			phi[i] = i - 1;
		}
		for(j = 1; i * prime[j] < MAXV; ++ j)
			if(i % prime[j]) phi[i * prime[j]] = phi[i] * phi[prime[j]];
			else{
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
	}
}
inline LL C(int n, int m){
	if(n < m) return 0LL;
	return (f[n] * inv[m] % MOD) * inv[n - m] % MOD;
}
void update(int pos){
	ans = (ans - (C(cnt[pos], k) * phi[pos] % MOD) + MOD) % MOD;
	ans = (ans + C(++ cnt[pos], k) * phi[pos]) % MOD;
}
void insert(int val){
	for(int i = 1; i <= val / i; ++ i){
		if(val % i) continue;
		update(i);
		if(i * i != val) update(val / i);
	}
}
int main(){
	int i, t; preCalc();
	scanf("%d%d%d", &n, &k, &q);
	for(i = f[0] = 1; i <= n + q; ++ i)
		f[i] = f[i - 1] * i % MOD;
	for(inv[0] = inv[1] = 1LL, i = 2; i <= n + q; ++ i)
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
	for(i = 1; i <= n + q; ++ i) inv[i] = inv[i] * inv[i - 1] % MOD;
	for(i = 1; i <= n; ++ i){
		scanf("%d", &t);
		insert(t);
	}
	for(i = 1; i <= q; ++ i){
		scanf("%d", &t);
		insert(t);
		printf("%I64d\n", ans);
	}
	return 0;
}