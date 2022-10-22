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

ll n, k, Q;
ll a[5005];
ll dp[5005][5005];
ll w[5005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> Q;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 1, n) dp[0][i] = 1;
	rep(i, 0, k-1){
		rep(j, 1, n){
			if(j+1 <= n) (dp[i+1][j+1] += dp[i][j]) %= mod;
			if(j-1 >= 1) (dp[i+1][j-1] += dp[i][j]) %= mod;
		}
	}
	rep(i, 0, k) rep(j, 1, n) (w[j] += dp[i][j] * dp[k-i][j] % mod) %= mod;
	
	ll ans = 0;
	rep(i, 1, n) ans += w[i] * a[i] % mod, ans %= mod;
	
	ll i, x;
	rep(q, 1, Q){
		cin >> i >> x;
		ans += mod - a[i] * w[i] % mod, ans %= mod;
		a[i] = x;
		ans += a[i] * w[i] % mod, ans %= mod;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}