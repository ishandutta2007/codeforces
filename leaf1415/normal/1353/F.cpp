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
llint h, w;
llint a[105][105];
llint dp[105][105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int y = 0; y <= 100; y++){
		for(int x = 0; x <= 100; x++){
			dp[x][y] = inf;
		}
	}
	dp[1][1] = 0;
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> w;
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				cin >> a[x][y];
			}
		}
		llint base = a[1][1];
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				a[x][y] -= x+y-2+base;
			}
		}
		
		llint ans = inf;
		for(int p = 1; p <= w; p++){
			for(int q = 1; q <= h; q++){
				llint base = a[p][q];
				if(base > 0) continue;
				for(int y = 1; y <= h; y++){
					for(int x = 1; x <= w; x++){
						if(x == 1 && y == 1) continue;
						if(a[x][y] < base){
							dp[x][y] = inf;
							continue;
						}
						dp[x][y] = min(dp[x-1][y], dp[x][y-1]) + a[x][y]-base;
					}
				}
				ans = min(ans, dp[w][h] - base);
			}
		}
		cout << ans << endl;
	}
	flush(cout);
	
	return 0;
}