#include <stdio.h>

const long long mod = 998244353;
long long n,inv[1001001]={0,1},fact[1001001]={1,1},ifact[1001001]={1,1};

int main()
{
	scanf ("%lld",&n);
	for (int i=2;i<=n;i++){
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		fact[i] = fact[i-1] * i % mod;
		ifact[i] = ifact[i-1] * inv[i] % mod;
	}

	long long ans = fact[n];

	for (int i=1;i<=n-2;i++){
		ans = (ans + fact[n] * ifact[n-i] % mod * (fact[n-i] - 1)) % mod;
	}
	printf ("%lld\n",ans);

	return 0;
}