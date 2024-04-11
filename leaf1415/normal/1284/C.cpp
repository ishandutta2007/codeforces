#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;

llint n, mod;

const int FACT_MAX = 300005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

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
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> mod;
	make_fact();
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		llint tmp = (n-i+1) * (n-i+1) % mod;
		tmp *= fact[i], tmp %= mod;
		tmp *= fact[n-i], tmp %= mod;
		ans += tmp, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}