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

ll n;
ll a[5005], mul[5005], minv[5005];
ll dp[2][10005], dp2[2][10005];
ll ans[10005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n;
	rep(i, 1, n-1) cin >> a[i];
	mul[0] = minv[0] = 1;
	rep(i, 1, n-1){
		mul[i] = mul[i-1] * a[i] % mod;
		minv[i] = modpow(mul[i], mod-2);
	}
	ll inv2 = (mod+1)/2;
	
	dp[n&1][0] = 1, dp2[n&1][0] = 1;
	for(int i = n-1; i >= 1; i--){
		
		rep(j, 0, 2*n) dp[i&1][j] = 0;
		dp[i&1][0] = 2, dp[i&1][1] = a[i]*2%mod, dp[i&1][2] = a[i]*(a[i]-1)%mod;
		if(i+2 <= n) dp[i&1][2] += a[i]*a[i+1]%mod*2%mod, dp[i&1][2] %= mod;
		rep(j, 3, 2*n-2){
			if(i+j <= n) dp[i&1][j] += mul[i+j-1] * minv[i-1] % mod * 2 % mod, dp[i&1][j] %= mod;
			dp[i&1][j] += a[i]*(a[i]-1) % mod * dp2[(i+1)&1][j-2] % mod, dp[i&1][j] %= mod;
		}
		rep(j, 1, 2*n) ans[j] += mul[i-1] * dp[i&1][j] % mod * inv2 % mod, ans[j] %= mod;
		
		
		rep(j, 0, 2*n) dp2[i&1][j] = 0;
		dp2[i&1][0] = 2, dp2[i&1][1] = a[i]*2%mod, dp2[i&1][2] = a[i]*a[i]%mod;
		if(i+2 <= n) dp2[i&1][2] += a[i]*a[i+1]%mod*2%mod, dp2[i&1][2] %= mod;
		rep(j, 3, 2*n-2){
			if(i+j <= n) dp2[i&1][j] += mul[i+j-1] * minv[i-1] % mod * 2 % mod, dp2[i&1][j] %= mod;
			dp2[i&1][j] += a[i]*a[i]%mod * dp2[(i+1)&1][j-2] % mod, dp2[i&1][j] %= mod;
		}
		
		//rep(j, 0, 2*n) cout << dp[i&1][j] << " "; cout << endl;
	}
	
	rep(i, 1, 2*n-2) cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}