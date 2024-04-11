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

using namespace std;
typedef pair<llint, llint> P;

llint n, r1, r2, r3, d;
llint a[1000005];
llint dp[1000005][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> r1 >> r2 >> r3 >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 2; j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	
	for(int i = 0; i < n; i++){
		llint c1 = a[i+1]*r1+r3, c2 = min((a[i+1]+1)*r1, r2);
		
		if(i < n-1) chmin(dp[i+1][0], dp[i][0] + c1 + d);
		else chmin(dp[i+1][0], dp[i][0] + c1);
		
		if(i < n-1) chmin(dp[i+1][1], dp[i][0] + c2 + d);
		else chmin(dp[i+1][0], dp[i][0] + c2 + 2*d + r1);
		
		if(i < n-1) chmin(dp[i+1][0], dp[i][1] + c1 + 3*d + r1);
		else chmin(dp[i+1][0], dp[i][1] + c1 + d + r1);
		
		if(i < n-1) chmin(dp[i+1][0], dp[i][1] + c2 + 3*d + 2*r1);
		else chmin(dp[i+1][0], dp[i][1] + c2 + 2*d + 2*r1);
	}
	cout << dp[n][0] << endl;
	
	return 0;
}