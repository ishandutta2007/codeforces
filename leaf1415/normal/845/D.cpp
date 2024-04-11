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
#define outl(x) cout << (x) << endl

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll dp[2][305][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	ll t, s, spd = 0;
	
	rep(j, 0, 301){
		rep(k, 0, 1){
			dp[0][j][k] = inf;
		}
	}
	dp[0][301][0] = 0;
	
	rep(i, 0, n-1){
		cin >> t;
		if(t == 1 || t == 3) cin >> s;
		if(t == 1) spd = s;
		
		rep(j, 0, 301){
			rep(k, 0, 1){
				dp[(i+1)%2][j][k] = inf;
			}
		}
		
		rep(j, 0, 301){
			rep(k, 0, 1){
				if(t <= 2) chmin(dp[(i+1)%2][j][k], dp[i%2][j][k]);
				else chmin(dp[(i+1)%2][j][k], dp[i%2][j][k] + 1);
				ll nj = j, nk = k;
				if(t == 3) nj = s;
				if(t == 4) nk = 0;
				if(t == 5) nj = 301;
				if(t == 6) nk = 1;
				chmin(dp[(i+1)%2][nj][nk], dp[i%2][j][k]);
			}
		}
		
		rep(j, 0, 301){
			rep(k, 0, 1){
				if(j < spd) dp[(i+1)%2][j][k] = inf;
				if(t == 2 && k == 1) dp[(i+1)%2][j][k] = inf;
			}
		}
	}
	
	ll ans = inf;
	rep(j, 0, 301){
		rep(k, 0, 1){
			chmin(ans, dp[n%2][j][k]);
		}
	}
	outl(ans);
	
	return 0;
}