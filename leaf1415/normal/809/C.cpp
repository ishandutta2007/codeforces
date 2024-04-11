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
#define SP << " " << 
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll Q;
ll dp[35][2][2][2];
ll dp2[35][2][2][2];

ll calc(ll x, ll y, ll z)
{
	if(x < 0 || y < 0) return 0;
	
	rep(i, 0, 31) rep(j, 0, 1) rep(k, 0, 1) rep(l, 0, 1) dp[i][j][k][l] = dp2[i][j][k][l] = 0;
	dp2[31][0][0][0] = 1;
	
	for(int i = 30; i >= 0; i--){
		rep(j, 0, 1) rep(k, 0, 1) rep(l, 0, 1){
			rep(m, 0, 1) rep(n, 0, 1){
				ll nj = j, nk = k, nl = l;
				if(j == 0 && (x&(1<<i)) == 0 && m == 1) continue;
				if(k == 0 && (y&(1<<i)) == 0 && n == 1) continue;
				if(l == 0 && (z&(1<<i)) == 0 && (m^n) == 1) continue;
				
				if((x&(1<<i)) && m == 0) nj = 1;
				if((y&(1<<i)) && n == 0) nk = 1;
				if((z&(1<<i)) && (m^n) == 0) nl = 1;
				
				dp[i][nj][nk][nl] += dp[i+1][j][k][l] + dp2[i+1][j][k][l] * ((m^n)<<i) % mod;
				dp[i][nj][nk][nl] %= mod;
				(dp2[i][nj][nk][nl] += dp2[i+1][j][k][l]) %= mod;
			}
		}
	}
	
	ll ret = dp[0][1][1][1] + dp2[0][1][1][1];
	return ret % mod;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	ll lx, ly, rx, ry, k;
	rep(q, 1, Q){
		cin >> lx >> ly >> rx >> ry >> k;
		ll ans = calc(rx, ry, k);
		ans += mod - calc(lx-1, ry, k), ans %= mod;
		ans += mod - calc(rx, ly-1, k), ans %= mod;
		ans += calc(lx-1, ly-1, k), ans %= mod;
		cout << ans << endl;
	}
	
	return 0;
}