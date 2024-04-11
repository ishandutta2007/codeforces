#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define llint long long
#define mod 1000000007

using namespace std;

llint n, k;
const int FACT_MAX = 1005;
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

llint comb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n >> k;
	if(k == 1){
		cout << 1 << endl;
		return 0;
	}
	llint ans = 0;
	for(int x = 0; x <= n; x++){
		for(int y = 0; y <= n; y++){
			llint m = (n-x)*(n-y);
			llint tmp = comb(n, x) * comb(n, y) % mod;
			tmp *= modpow(k, m), tmp %= mod;
			tmp *= modpow(k-1, n*n-m), tmp %= mod;
			if((x+y)%2) ans += mod - tmp, ans %= mod;
			else ans += tmp, ans %= mod;
		}
	}
	cout << ans << endl;
	
	return 0;
}