#include <iostream>
#define llint long long
#define mod 998244353

using namespace std;

llint n;
llint fact[1000005];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

int main(void)
{
	cin >> n;
	
	fact[0] = 1;
	for(int i = 1; i < 1000005; i++){
		fact[i] = fact[i-1] * i % mod;
	}
	
	llint ans = n*(fact[n])%mod;
	for(int i = 1; i <= n; i++){
		ans += mod - fact[n]*modpow(fact[n-i], mod-2)%mod;
		ans %= mod;
	}
	ans += fact[n], ans %= mod;
	cout << ans << endl;
	
	return 0;
}