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
llint d[200005], dsum[200005];

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
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> d[i];
	sort(d+1, d+n+1);
	
	for(int i = 1; i <= n; i++) dsum[i] = dsum[i-1] + d[i], dsum[i] %= mod;
	
	llint a, b;
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		llint p = lower_bound(d+1, d+n+1, b) - d;
		llint d = p-1, u = n - d;
		llint ans = dsum[d] * max(0LL, u+1-a) % mod * modpow(u+1, mod-2) % mod;
		ans += (dsum[n] - dsum[d] + mod) % mod * max(0LL, u-a) % mod * modpow(u, mod-2) % mod, ans %= mod;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}