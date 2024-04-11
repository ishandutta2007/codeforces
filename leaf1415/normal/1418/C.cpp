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

llint T;
llint n;
llint a[200005];
llint dp[200005][2][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		for(int i = 0; i <= n; i++){
			for(int j = 0; j < 2; j++){
				for(int k = 0; k < 2; k++){
					dp[i][j][k] = inf;
				}
			}
		}
		dp[0][1][0] = 0;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 2; j++){
				for(int k = 0; k < 2; k++){
					if(k+1 < 2) chmin(dp[i+1][j][k+1], dp[i][j][k] + a[i+1]*j);
					chmin(dp[i+1][j^1][0], dp[i][j][k] + a[i+1]*j);
				}
			}
		}
		
		llint ans = inf;
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				ans = min(ans, dp[n][j][k]);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}