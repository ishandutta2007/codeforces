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

llint n, m;
llint a[100005];
llint p[300005], q[300005], r[300005];
llint t[300005], dp[300005];
llint ninv, minv;

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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], m += a[i];
	ninv = modpow(n-1, mod-2), minv = modpow(m, mod-2);
	
	for(int i = 0; i < m; i++){
		p[i] = i * minv % mod;
		r[i] = (m-i) * minv % mod * ninv % mod;
		q[i] = r[i] * (n-2) % mod;
	}
	
	t[0] = modpow(r[0], mod-2);
	for(int i = 1; i < m; i++){
		t[i] = p[i] * t[i-1] % mod + 1;
		t[i] *= modpow((1-p[i]-q[i]+2LL*mod)%mod, mod-2), t[i] %= mod;
	}
	for(int i = m-1; i >= 0; i--) dp[i] = dp[i+1] + t[i], dp[i] %= mod;
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		ans += dp[a[i]], ans %= mod;
	}
	ans += mod - dp[0] * (n-1) % mod, ans %= mod;
	ans *= modpow(n, mod-2), ans %= mod;
	cout << ans << endl;
	
	return 0;
}