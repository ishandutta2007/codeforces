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
ll h, w;
char c[505][505];
ll dp[505][505];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> h >> w;
		rep(y, 1, h) rep(x, 1, w) cin >> c[x][y];
		
		for(int y = h; y >= 1; y--){
			rep(x, 1, w){
				if(c[x][y] == '.'){
					dp[x][y] = 0;
					continue;
				}
				dp[x][y] = 1;
				if(y+1 > h || x-1 < 1 || x+1 > w) continue;
				dp[x][y] = min(dp[x-1][y+1], min(dp[x][y+1], dp[x+1][y+1])) + 1;
			}
		}
		ll ans = 0;
		rep(y, 1, h){
			rep(x, 1, w){
				ans += dp[x][y];
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}