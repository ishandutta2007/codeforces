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

ll T;
ll n;
ll a[3005];
ll sum[3005][3005];
ll dp[3005][3005];

ll get(ll sx, ll sy, ll tx, ll ty)
{
	if(sx > tx || sy > ty) return 0;
	return sum[tx][ty] - sum[sx-1][ty] - sum[tx][sy-1] + sum[sx-1][sy-1];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		
		rep(l, 1, n) rep(r, 1, n) sum[l][r] = 0;
		rep(i, 1, n){
			if(a[i] == 0) continue;
			sum[i][i+a[i]]++;
		}
		rep(l, 1, n) rep(r, 1, n) sum[l][r] += sum[l-1][r] + sum[l][r-1] - sum[l-1][r-1];
		
		rep(i, 1, n) rep(j, 1, n) dp[i][j] = inf;
		dp[1][1] = 0;
		
		rep(i, 1, n-1){
			if(a[i] == 0) continue;
			ll mn = inf;
			rep(j, 1, n){
				if(j > i+a[i]) break;
				chmin(dp[j][i+a[i]], mn + get(i+1, j, j-1, n));
				chmin(mn, dp[i][j]);
			}
		}
		/*rep(i, 1, n){
			rep(j, 1, n){
				if(dp[i][j] > inf/2) cout << "x ";
				else cout << dp[i][j] << " ";
			}
			 cout << endl;
		}*/
		cout << dp[n][n] << endl;
	}
	
	return 0;
}