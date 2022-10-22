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

const int FACT_MAX = 600005;
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
llint l[300005], r[300005];
llint lcnt[600005], rcnt[600005];
vector<llint> comp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		comp.push_back(l[i]);
		comp.push_back(r[i]);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int i = 1; i <= n; i++){
		l[i] = lower_bound(comp.begin(), comp.end(), l[i]) - comp.begin();
		r[i] = lower_bound(comp.begin(), comp.end(), r[i]) - comp.begin();
	}
	for(int i = 1; i <= n; i++) lcnt[l[i]]++, rcnt[r[i]]++;
	
	
	llint ans = 0, cnt = 0;
	for(int i = 0; i < comp.size(); i++){
		for(int j = 0; j < lcnt[i]; j++){
			cnt++;
			if(cnt-1 >= k-1) ans += comb(cnt-1, k-1), ans %= mod;
		}
		cnt -= rcnt[i];
	}
	cout << ans << endl;
	
	return 0;
}