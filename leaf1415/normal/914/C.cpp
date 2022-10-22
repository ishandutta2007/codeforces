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

string s;
ll n, k;
ll dp[1005];

ll calc(ll x)
{
	ll ret = 0;
	for(;x;x/=2) ret += x&1;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> s >> k;
	n = s.size();
	rep(i, 2, 1000) dp[i] = dp[calc(i)] + 1;
	if(k == 0){
		cout << 1 << endl;
		return 0;
	}
	
	ll ans = 0;
	rep(i, 1, n){
		if(dp[i] != k-1) continue;
		if(i == 1) ans += mod-1, ans %= mod;
		ll cnt = 0;
		rep(j, 0, n-1){
			if(s[j] == '0') continue;
			if(i-cnt >= 0 && n-j-1 >= i-cnt){
				ans += comb(n-j-1, i-cnt), ans %= mod;
			}
			cnt++;
		}
		if(cnt == i) ans++, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}