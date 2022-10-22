#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint fact[1000005], fact_inv[1000005];

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

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < 1000005; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	for(int i = 0; i < 1000005; i++){
		fact_inv[i] = modpow(fact[i], mod-2);
	}
}

llint comb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

llint n, m, a, b;

int main(void)
{
	cin >> n >> m >> a >> b;
	make_fact();
	
	llint N = modpow(n, n-1), inv = modpow(n, mod-2);
	
	llint ans = 0;
	for(int i = 1; i <= min(m, n-1); i++){
		llint tmp = 1;
		
		tmp *= comb(m-1, m-i), tmp %= mod;
		tmp *= fact[n-2], tmp %= mod;
		tmp *= fact_inv[n-i-1], tmp %= mod;
		
		if(n-i-2 >= 0){
			tmp *= (i+1), tmp %= mod;
			tmp *= modpow(n, n-i-2), tmp %= mod;
		}
		
		tmp *= modpow(m, n-1-i), tmp %= mod;
		
		ans += tmp, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}