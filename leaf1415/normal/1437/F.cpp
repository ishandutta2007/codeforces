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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18
#define mod 998244353

using namespace std;

typedef long long llint;
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

llint n;
llint a[5005], b[5005];
llint sum[5005];
llint r[5005];
llint dp[5005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	sort(a+1, a+n+1);
	
	if(a[n-1]*2 > a[n]){
		cout << 0 << endl;
		return 0;
	}
	
	map<llint, llint> mp;
	rep(i, 1, n) mp[a[i]]++;
	
	llint id = 1;
	for(auto x : mp){
		a[id] = x.first;
		b[id] = x.second;
		id++;
	}
	n = mp.size();
	
	rep(i, 1, n) sum[i] = sum[i-1] + b[i];
	rep(i, 1, n){
		rep(j, 1, n) if(2*a[j] <= a[i]) r[i] = j;
	}
	
	//rep(i, 1, n) cout << r[i] << " "; cout << endl;
	
	dp[0] = 1;
	rep(i, 0, n-1){
		rep(j, i+1, n){
			if(a[i]*2 > a[j]) continue;
			llint x = sum[r[j]] - sum[r[i]];
			if(i > 0) x--;
			//cout << i << " " << j << " " << x << endl;
			dp[j] += dp[i] * comb(sum[n] - (sum[r[j]] + 1) + x , x) % mod * fact[x] % mod * b[j] % mod;
			//cout << comb(sum[n] - (sum[r[j]] + 1) + x , x) << endl;
			if(dp[j] >= mod) dp[j] -= mod;
		}
	}
	
	//rep(i, 0, n) cout << dp[i] << " "; cout << endl;
	
	cout << dp[n] << endl;
	
	return 0;
}