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

llint h, w;
char c[2005][2005];
llint mx[2005][2005];
llint dp[2005][2005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cin >> c[x][y];
		}
	}
	
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			mx[x][y] = inf;
		}
	}
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			dp[x][y] = 1;
			if(c[x][y] == c[x-1][y] && c[x][y] == c[x][y-1]){
				dp[x][y] = max(dp[x][y], min(dp[x-1][y], dp[x][y-1])+1);
			}
			mx[x][y] = min(mx[x][y], dp[x][y]);
		}
	}
	for(int y = 1; y <= h; y++){
		for(int x = w; x >= 1; x--){
			dp[x][y] = 1;
			if(c[x][y] == c[x+1][y] && c[x][y] == c[x][y-1]){
				dp[x][y] = max(dp[x][y], min(dp[x+1][y], dp[x][y-1])+1);
			}
			mx[x][y] = min(mx[x][y], dp[x][y]);
		}
	}
	for(int y = h; y >= 1; y--){
		for(int x = 1; x <= w; x++){
			dp[x][y] = 1;
			if(c[x][y] == c[x-1][y] && c[x][y] == c[x][y+1]){
				dp[x][y] = max(dp[x][y], min(dp[x-1][y], dp[x][y+1])+1);
			}
			mx[x][y] = min(mx[x][y], dp[x][y]);
		}
	}
	for(int y = h; y >= 1; y--){
		for(int x = w; x >= 1; x--){
			dp[x][y] = 1;
			if(c[x][y] == c[x+1][y] && c[x][y] == c[x][y+1]){
				dp[x][y] = max(dp[x][y], min(dp[x+1][y], dp[x][y+1])+1);
			}
			mx[x][y] = min(mx[x][y], dp[x][y]);
		}
	}
	
	llint ans = 0;
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			ans += mx[x][y];
		}
	}
	cout << ans << endl;
	
	return 0;
}