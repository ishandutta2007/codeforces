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
	if(n < k || k < 0) return 0;
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

llint n, m;
llint l[300005], r[300005];
llint a[25], b[25];
llint c[300005];
llint sum[45][300005];
llint pop[1<<20];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];
	for(int i = 0; i < m; i++) cin >> a[i] >> b[i];
	
	for(int i = 1; i <= n; i++) c[l[i]]++, c[r[i]+1]--;
	for(int i = 1; i <= n; i++) c[i] += c[i-1];
	
	for(int i = 1; i <= n; i++){
		sum[0][i] = sum[0][i-1] + comb(c[i], i), sum[0][i] %= mod;
	}
	for(int i = 1; i < 45; i++){
		for(int j = 1; j <= n; j++){
			sum[i][j] = sum[i][j-1] + comb(c[j]-i, j-i) + mod - comb(c[j]-(i-1), j-(i-1));
			sum[i][j] %= mod;
		}
	}
	
	llint M = 1<<m, ans = 0;
	for(int i = 1; i < M; i++) pop[i] = pop[i&(i-1)] + 1;
	for(int i = 0; i < M; i++){
		set<llint> S;
		for(int j = 0; j < m; j++){
			if(i & (1<<j)) S.insert(a[j]), S.insert(b[j]);
		}
		llint L = 1, R = n;
		for(auto it = S.begin(); it != S.end(); it++){
			L = max(L, l[*it]), R = min(R, r[*it]);
		}
		if(L > R) continue;
		
		llint tmp = 0;
		for(int j = 0; j <= S.size(); j++){
			tmp += sum[j][R] - sum[j][L-1] + mod;
			tmp %= mod;
		}
		if(pop[i] % 2) ans += mod - tmp, ans %= mod;
		else ans += tmp, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}