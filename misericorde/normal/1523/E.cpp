#include <bits/stdc++.h>

using ll = long long;
const int mod = 1e9 + 7;
const int lim = 1e6;

int n,k,fac[2 * lim + 100],ifac[2 * lim + 100];

int binom(int n,int m) { 
	if (n < 0 || m < 0 || n < m) return 0;
	return (ll) fac[n] * ifac[m] % mod * ifac[n - m] % mod; 
}

int inv(int x) { return x == 1 ? 1 : (ll) ( mod - mod / x ) * inv(mod % x) % mod; }

void solve() {
	scanf("%d%d",&n,&k);
	fac[0] = ifac[0] = ifac[1] = 1;
	for (int i = 1; i <= lim; ++ i) fac[i] = (ll) fac[i - 1] * i % mod;
	for (int i = 2; i <= lim; ++ i) ifac[i] = (ll) (mod - mod / i) * ifac[mod % i] % mod;
	for (int i = 1; i <= lim; ++ i) ifac[i] = (ll) ifac[i] * ifac[i - 1] % mod;
	int ans = 0;
	for (int i = 1; (i - 1) * k <= n + 2 && i <= n; ++ i) {
		int tmp = binom(n - i * (k - 1),i);
		for (int j = n - k + 2; j <= n; ++ j) {
			tmp = (tmp + binom(j - 1 - (i - 1) * (k - 1), i - 1)) % mod;
		}
		//printf("%d %d\n",tmp,binom(n,i));
		ans = (ans + (ll) tmp * inv(binom(n,i)) % mod) % mod;
	} ans = (ans + 1) % mod;
	printf("%d\n",ans);
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}