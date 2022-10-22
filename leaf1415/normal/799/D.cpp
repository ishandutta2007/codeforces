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

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll a, b, h, w, n;
ll x[100005];
ll dp[55][100005];

ll calc(ll h, ll w)
{
	chmin(h, a), chmin(w, b);
	
	rep(i, 0, n) rep(j, 1, a) dp[i][j] = 0;
	dp[0][h] = w;
	
	rep(i, 0, n-1){
		rep(j, 1, a){
			chmax(dp[i+1][min(a,j*x[i+1])], dp[i][j]);
			chmax(dp[i+1][j], min(b,dp[i][j]*x[i+1]));
		}
	}
	
	rep(i, 0, n){
		if(dp[i][a] >= b){
			return i;
		}
	}
	return inf;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> h >> w >> n;
	rep(i, 1, n) cin >> x[i];
	sort(x+1, x+n+1), reverse(x+1, x+n+1);
	chmin(n, 50LL);
	
	ll ans = min(calc(h, w), calc(w, h));
	if(ans > inf/2) ans = -1;
	cout << ans << endl;
	
	
	
	return 0;
}