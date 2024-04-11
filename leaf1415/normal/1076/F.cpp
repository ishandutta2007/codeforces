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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n, k;
llint a[300005][2];
llint dp[300005][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i][0];
	rep(i, 1, n) cin >> a[i][1];
	
	rep(i, 0, n){
		rep(j, 0, 1){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	
	rep(i, 0, n-1){
		rep(j, 0, 1){
			if(dp[i][j] > k) continue;
			
			llint x = a[i+1][j], y = a[i+1][1-j];
			if(x <= y && y <= k*x) chmin(dp[i+1][j], 1LL);
			if(x+1 <= y) chmin(dp[i+1][1-j], max(1LL, y-k*x));
			
			if(x+((i>0)?1:0) >= y+1) chmin(dp[i+1][j], max(1LL, x-(k*y-dp[i][j])));
			if(x+((i>0)?1:0) >= y && x <= k*y-dp[i][j]) chmin(dp[i+1][1-j], 1LL);
		}
	}
	
	/*rep(i, 0, n){
		rep(j, 0, 1){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	if(dp[n][0] <= k || dp[n][1] <= k) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}