#include <cstdio>
#include <cstring>
typedef long long int ll;
const int MAXN = 100005;
const ll MOD = 1000000007;

char num[MAXN];
int cnt[15], n, k;
ll f[MAXN], inv[MAXN], base[15];

inline ll C(int n, int m){
	if(n < m) return 0;
	return ((f[n] * inv[m]) % MOD * inv[n - m]) % MOD;
}
int main(){
	int i, j, ans = 0;
	for(f[0] = i = 1; i < MAXN; ++ i)
		f[i] = (f[i - 1] * i) % MOD;
	inv[MAXN - 1] = inv[0] = 1;
	ll c = MOD - 2, b = f[MAXN - 1];
	while(c){
		if(c & 1) inv[MAXN - 1] = (inv[MAXN - 1] * b) % MOD;
		b = (b * b) % MOD;
		c >>= 1;
	}
	for(i = MAXN - 2; i; -- i)
		inv[i] = (inv[i + 1] * (i + 1)) % MOD;
	scanf("%d%d%s", &n, &k, num);
	for(i = 0; i < n; ++ i) cnt[num[i] - '0'] ++;
	for(i = 1; i <= 9; ++ i) base[i] = i;
	for(i = n - 1; i >= 0; -- i){
		for(j = 1; j <= 9; ++ j)
			if(cnt[j]){
				if(j != (num[i] - '0')){
					ans = (((C(i - 1, k - 1) * base[j]) % MOD * cnt[j]) % MOD + ans) % MOD;
					base[j] = (base[j] * 10) % MOD;
				}else ans = (((C(i - 1, k - 1) * base[j]) % MOD * (cnt[j] - 1)) % MOD + ans) % MOD;
			}
		ans = ((C(i, k) * base[num[i] - '0']) % MOD + ans) % MOD;
		base[num[i] - '0'] = (base[num[i] - '0'] * 10) % MOD;
		cnt[num[i] - '0'] --;
	}
	printf("%d\n", ans);
	return 0;
}