#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

const int FACT_MAX = 4000005;
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

llint icomb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact_inv[n];
	ret *= fact[k], ret %= mod;
	ret *= fact[n-k], ret %= mod;
	return ret;
}

llint n, m;
llint dp[2000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n >> m;
	dp[n] = 0;
	
	llint sum = 0, sum2 = 1, csum = 1;
	for(int i = n-1; i >= 0; i--){
		llint bunsi = comb(m+n-i-1, m-1), bunbo = icomb(m+n-i, m);
		llint divi = (1 + mod - bunsi * bunbo % mod);
		if(divi >= mod) divi -= mod;
		llint alpha = (n+m+1) * modpow(n+m-i+1, mod-2) % mod;
		
		csum += bunsi;
		if(csum >= mod) csum -= mod;
		sum2 += csum;
		if(sum2 >= mod) sum2 -= mod;
		
		llint tmp = (sum + alpha * sum2 % mod);
		if(tmp >= mod) tmp -= mod;
		
		tmp *= bunbo, tmp %= mod;
		tmp *= modpow(divi, mod-2), tmp %= mod;
		
		dp[i] = tmp;
		sum += bunsi * dp[i] % mod;
		if(sum >= mod) sum -= mod;
	}
	cout << dp[0] << endl;
	
	return 0;
}