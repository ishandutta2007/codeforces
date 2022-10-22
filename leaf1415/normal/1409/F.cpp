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

llint n, k;
string s, t;
llint dp[205][205][205];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	cin >> s >> t;
	
	if(t[0] == t[1]){
		llint cnt = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == t[0]) cnt++;
		}
		cnt = min(cnt+k, n);
		cout << cnt*(cnt-1)/2 << endl;
		return 0;
	}
	
	s = "#" + s;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= k; j++){
			for(int l = 0; l <= n; l++){
				dp[i][j][l] = -inf;
			}
		}
	}
	dp[0][0][0] = 0;
				
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= k; j++){
			for(int l = 0; l <= n; l++){
				if(s[i+1] == t[0]){
					if(l+1 <= n) chmax(dp[i+1][j][l+1], dp[i][j][l]);
				}else if(s[i+1] == t[1]) chmax(dp[i+1][j][l], dp[i][j][l] + l);
				else chmax(dp[i+1][j][l], dp[i][j][l]);
				
				if(j+1 <= k && l+1 <= n) chmax(dp[i+1][j+1][l+1], dp[i][j][l]);
				if(j+1 <= k) chmax(dp[i+1][j+1][l], dp[i][j][l] + l);
			}
		}
	}
	
	llint ans = 0;
	for(int j = 0; j <= k; j++){
		for(int l = 0; l <= n; l++){
			ans = max(ans, dp[n][j][l]);
		}
	}
	cout << ans << endl;
	
	return 0;
}