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
#define mod 1000000007

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

llint n, x, p;
llint a[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n >> x >> p;
	
	llint l = 0, r = n, m;
	while(l < r){
		m = (l+r)/2;
		if(m < p+1){
			a[m] = -1;
			l = m+1;
		}
		else{
			a[m] = 1;
			r = m;
		}
	}
	
	llint lcnt = 0, hcnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > 0) hcnt++;
		if(a[i] < 0) lcnt++;
	}
	lcnt--;
	
	if(lcnt > x-1 || hcnt > n-x){
		cout << 0 << endl;
		return 0;
	}
	
	llint ans = comb(x-1, lcnt) * comb(n-x, hcnt) % mod;
	ans *= fact[lcnt], ans %= mod;
	ans *= fact[hcnt], ans %= mod;
	ans *= fact[(n-1)-(lcnt+hcnt)], ans %= mod;
	cout << ans << endl;
	
	return 0;
}