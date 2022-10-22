#include <iostream>
#include <algorithm>
#include <set>
#define llint long long
#define mod 998244353
#define rep(i, s, t) for(llint (i) = (s); (i) <= (t); (i)++)

using namespace std;

llint n, m;

const int FACT_MAX = 400005;
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
	
	cin >> n >> m;
	
	if(n == 2){
		cout << 0 << endl;
		return 0;
	}
	
	llint ans = 0;
	rep(i, 1, m-1){
		llint tmp = comb(m-1, n-2);
		if(i-1 >= n-2) tmp += mod - comb(i-1, n-2), tmp %= mod;
		ans += tmp, ans %= mod;
	}
	ans *= modpow(2, n-3), ans %= mod;
	cout << ans << endl;
	
	return 0;
}