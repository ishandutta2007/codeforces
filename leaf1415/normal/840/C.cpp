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
	if(n < k || n < 0 || k < 0) return 0;
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

ll n;
ll a[305];
ll dp[305][305];
map<ll, ll> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 1, n){
		map<ll, ll> mp;
		for(int j = 2; j*j <= a[i]; j++){
			while(a[i] % j == 0){
				mp[j]++;
				a[i] /= j;
			}
		}
		if(a[i] > 1) mp[a[i]]++;
		
		ll mul = 1;
		for(auto x : mp) if(x.second % 2) mul *= x.first;
		a[i] = mul;
	}
	rep(i, 1, n) mp[a[i]]++;
	
	vector<ll> vec;
	for(auto x : mp) vec.push_back(x.second);
	ll m = vec.size();
	
	dp[0][0] = 1;
	ll sum = 0;
	rep(i, 0, m-1){
		ll N = vec[i];
		rep(j, 0, n){
			rep(k, 0, N){
				rep(l, 0, N){
					ll mul = comb(sum+1-j, k) * comb(j, l) % mod;
					mul *= comb(N-1, k+l-1), mul %= mod;
					mul *= fact[N], mul %= mod;
					ll nj = j-l+N-(k+l);
					if(nj >= 0 && nj <= n) (dp[i+1][nj] += mul * dp[i][j] % mod) %= mod;
				}
			}
		}
		sum += N;
	}
	
	cout << dp[m][0] << endl;
	
	return 0;
}