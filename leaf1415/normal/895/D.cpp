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


string s, t;

ll calc(string t)
{
	//cout << s << " " << t << endl;
	ll cnt[26] = {};
	for(auto c : s) cnt[c-'a']++;

	ll mul = fact[s.size()];
	rep(i, 0, 25) mul *= fact_inv[cnt[i]], mul %= mod;

	ll ans = 0, len = t.size();
	for(auto c : t){
		rep(j, 0, c-'a'-1){
			if(cnt[j] == 0) continue;
			ll x = mul;
			x *= fact_inv[len] * fact[len-1] % mod, x %= mod;
			x *= fact[cnt[j]] * fact_inv[cnt[j]-1] % mod, x %= mod;
			//cout << c << " " << (char)(j+'a') << " " << x << endl;
			ans += x, ans %= mod;
		}
		if(cnt[c-'a'] == 0) break;
		mul *= fact_inv[len] * fact[cnt[c-'a']] % mod, mul %= mod;
		len--, cnt[c-'a']--;
		mul *= fact[len] * fact_inv[cnt[c-'a']] % mod, mul %= mod;
	}
	return ans;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();

	cin >> s >> t;
	ll ans = calc(t) - calc(s) + mod - 1 + mod;
	cout << ans % mod << endl;

	return 0;
}