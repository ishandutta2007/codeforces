#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#define llint long long
#define inf 1000000000
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> L;

llint n, T;
llint t[200005];
llint inv2;

const int FACT_MAX = 200005;
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

llint calc(llint t, llint i, llint sum)
{
	llint ret = 0;
	llint l =  T-(t-1) - sum, r = T - sum;
	l = max(l, 0LL), r = min(r, i);
	//cout << l << " " << r << endl;
	if(l > r) return 0;
	for(int j = l; j <= r; j++){
		ret += comb(i, j) * modpow(inv2, i) % mod, ret %= mod;
	}
	
	//cout << ret << endl;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n >> T;
	for(int i = 1; i <= n; i++) cin >> t[i];
	inv2 = modpow(2, mod-2);
	
	llint ans = 0, sum = 0;
	for(llint i = 0; i < n; i++){
		llint pro = 0;
		pro += inv2 * calc(t[i+1], i, sum) % mod, pro %= mod;
		pro += inv2 * calc(t[i+1]+1, i, sum) % mod, pro %= mod;
		ans += pro * i % mod, ans %= mod;
		//cout << "p" << pro << endl;
		sum += t[i+1];
	}
	ans += calc(inf, n, sum) % mod * n % mod, ans %= mod;
	cout << ans << endl;
	
	return 0;
}