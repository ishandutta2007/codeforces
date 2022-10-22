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

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<P, ll> T;

ll n;
ll a[300005];
ll dp[300005][105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], a[i] /= 100;
	
	rep(i, 0, n) rep(j, 0, 100) dp[i][j] = inf;
	dp[0][0] = 0;
	
	rep(i, 0, n-1){
		rep(j, 0, 100){
			ll x = min(j, a[i+1]);
			chmin(dp[i+1][j-x], dp[i][j] + a[i+1]-x);
			if(j+a[i+1]/10 <= 100) chmin(dp[i+1][j+a[i+1]/10], dp[i][j] + a[i+1]);
		}
	}
	ll ans = inf;
	rep(i, 0, 100) chmin(ans, dp[n][i]);
	cout << ans*100 << endl;
	
	return 0;
}