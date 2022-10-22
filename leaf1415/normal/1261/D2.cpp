#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#define llint long long
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

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

llint n, k;
llint h[200005];
llint beki[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> h[i];
	make_fact();
	
	llint m = 0;
	for(int i = 0; i < n; i++){
		if(h[i] == h[(i+1)%n]) m++;
	}
	m = n-m;
	
	beki[0] = 1;
	for(int i = 1; i <= n; i++) beki[i] = beki[i-1] * (k-2) % mod;
	
	llint ans = 0;
	for(int i = 0; 2*i <= m; i++){
		llint tmp = comb(m, 2*i) * comb(2*i, i) % mod;
		tmp *= beki[m-2*i], tmp %= mod;
		ans += tmp, ans %= mod;
	}
	ans *= modpow(k, n-m), ans %= mod;
	
	ans = modpow(k, n) - ans + mod, ans %= mod;
	ans *= modpow(2, mod-2), ans %= mod;
	cout << ans << endl;
	
	return 0;
}