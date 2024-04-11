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

const int FACT_MAX = 1000005;
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

ll n, k;
ll dp[1000015];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n >> k;
	chmin(k, n);
	ll m = n+5;
	
	dp[0] = 1;
	ll p = 0, mul = 1, sum = 1;
	//rep(j, 0, m-1) cout << dp[j]*mul << " "; cout << endl;
	
	rep(i, 2, n){
		mul *= i-1, mul %= mod;
		p = (p+m-1)%m;
		ll pre = dp[(p+k)%m], suc = sum * modpow(i-1, mod-2) % mod;
		sum += suc - pre + mod, sum %= mod;
		dp[p] = suc;
		//rep(j, 0, m-1) cout << dp[(p+j)%m]*mul%mod << " "; cout << endl;
	}
	ll ans = 0;
	rep(i, 0, n) ans += dp[(p+i)%m], ans %= mod;
	ans *= mul, ans %= mod;
	
	ans = fact[n] - ans + mod, ans %= mod;
	cout << ans << endl;
	
	return 0;
}