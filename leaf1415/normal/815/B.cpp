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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
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
ll a[200005];
ll b[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	if(n <= 100){
		ll sgn = 1;
		rep(i, 1, n){
			rep(j, 1, n-i){
				b[j] = a[j] + sgn*a[j+1] + mod, b[j] %= mod;
				sgn *= -1;
			}
			rep(j, 1, n-1) a[j] = b[j];
		}
		cout << a[1] << endl;
		return 0;
	}
	
	ll sgn = 1;
	while(n % 2 || sgn == -1){
		rep(j, 1, n-1){
			b[j] = a[j] + sgn*a[j+1] + mod, b[j] %= mod;
			sgn *= -1;
		}
		rep(j, 1, n-1) a[j] = b[j];
		n--;
	}
	
	sgn = 1;
	if(n*(n-1)/2%2 == 0) sgn = -1;
	
	ll ans = 0;
	rep(i, 1, n/2){
		ans += comb(n/2-1, i-1) * a[2*i-1] % mod, ans %= mod;
		ans += mod + comb(n/2-1, i-1) * a[2*i] % mod * sgn, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}