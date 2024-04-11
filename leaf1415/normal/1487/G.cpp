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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18
#define mod 998244353

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll c[26];
ll dp[2][405][405][4][4];
ll sum[405][405];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 0, 25) cin >> c[i];
	
	dp[0][0][0][3][3] = 1;
	rep(i, 0, n-1){
		rep(j, 0, n) rep(k, 0, n) rep(l, 0, 3) rep(m, 0, 3) dp[(i+1)&1][j][k][l][m] = 0;
		rep(j, 0, n) rep(k, 0, n){
			rep(l, 0, 3) rep(m, 0, 3){
				if(l != 0 && j+1 <= n) (dp[(i+1)&1][j+1][k][m][0] += dp[i&1][j][k][l][m]) %= mod;
				if(l != 1 && k+1 <= n) (dp[(i+1)&1][j][k+1][m][1] += dp[i&1][j][k][l][m]) %= mod;
				if(l != 2) (dp[(i+1)&1][j][k][m][2] += dp[i&1][j][k][l][m] * 24) %= mod;
				if(l == 2) (dp[(i+1)&1][j][k][m][2] += dp[i&1][j][k][l][m] * 23) %= mod;
			}
		}
	}
	rep(j, 0, n) rep(k, 0, n) rep(l, 0, 3) rep(m, 0, 3) sum[j][k] += dp[n&1][j][k][l][m], sum[j][k] %= mod;
	
	
	ll ans = 26 * 26;
	rep(i, 3, n) ans *= 25, ans %= mod;
	
	rep(i, 0, 25) rep(j, c[i]+1, n) rep(k, 0, n) (ans += mod - sum[j][k]) %= mod;
	
	rep(i, 0, 25){
		rep(j, 0, 25){
			if(i >= j) continue;
			rep(k, c[i]+1, n) rep(l, c[j]+1, n) (ans += sum[k][l]) %= mod;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}