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

llint R, G, B;
llint r[205], g[205], b[205];
llint dp[205][205][205];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> R >> G >> B;
	for(int i = 1; i <= R; i++) cin >> r[i];
	for(int i = 1; i <= G; i++) cin >> g[i];
	for(int i = 1; i <= B; i++) cin >> b[i];
	
	sort(r+1, r+R+1), reverse(r+1, r+R+1);
	sort(g+1, g+G+1), reverse(g+1, g+G+1);
	sort(b+1, b+B+1), reverse(b+1, b+B+1);
	
	for(int i = 0; i <= R; i++){
		for(int j = 0; j <= G; j++){
			for(int k = 0; k <= B; k++){
				dp[i][j][k] = -inf;
			}
		}
	}
	dp[0][0][0] = 0;
	for(int i = 0; i <= R; i++){
		for(int j = 0; j <= G; j++){
			for(int k = 0; k <= B; k++){
				if(i+1 <= R && j+1 <= G) chmax(dp[i+1][j+1][k], dp[i][j][k] + r[i+1]*g[j+1]);
				if(j+1 <= G && k+1 <= B) chmax(dp[i][j+1][k+1], dp[i][j][k] + g[j+1]*b[k+1]);
				if(k+1 <= B && i+1 <= R) chmax(dp[i+1][j][k+1], dp[i][j][k] + b[k+1]*r[i+1]);
				if(i+2 <= R && j+2 <= G && k+2 <= B){
					chmax(dp[i+2][j+2][k+2], dp[i][j][k] + r[i+1]*g[j+2]+g[j+1]*b[k+2]+b[k+1]*r[i+2]);
					chmax(dp[i+2][j+2][k+2], dp[i][j][k] + r[i+1]*b[k+2]+g[j+1]*r[i+2]+b[k+1]*g[j+2]);
				}
			}
		}
	}
	
	llint ans = 0;
	for(int i = 0; i <= R; i++){
		for(int j = 0; j <= G; j++){
			for(int k = 0; k <= B; k++){
				ans = max(ans, dp[i][j][k]);
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}