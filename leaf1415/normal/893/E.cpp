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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18
#define mod 1000000007


using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;


const int FACT_MAX = 2000005;
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

ll Q;
ll prime[1000005];
map<ll, ll> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	rep(i, 2, 1000000){
		if(prime[i]) continue;
		for(int j = 2*i; j < 1000005; j+=i) prime[j] = i;
	}
	
	cin >> Q;
	ll x, y;
	while(Q--){
		cin >> x >> y;
		mp.clear();
		while(prime[x]){
			mp[prime[x]]++;
			x /= prime[x];
		}
		if(x > 1) mp[x]++;
		
		ll ans = 1;
		for(auto x : mp){
			ll d = x.second;
			ans *= comb(y-1+d, d), ans %= mod;
		}
		ans *= modpow(2, y-1), ans %= mod;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}