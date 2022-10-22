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
llint n, K, z;
llint a[100005];
llint dp[100005][6][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> K >> z;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		for(int i = 0; i <= K; i++){
			for(int j = 0; j <= z; j++){
				for(int k = 0; k < 2; k++){
					dp[i][j][k] = -inf;
				}
			}
		}
		dp[0][0][0] = a[1];
		
		for(int i = 0; i < K; i++){
			for(int j = 0; j <= z; j++){
				llint pos = 1 + i - 2*j;
				if(pos <= 0) continue;
				for(int k = 0; k < 2; k++){
					if(pos+1 <= n) chmax(dp[i+1][j][0], dp[i][j][k] + a[pos+1]);
					if(pos-1 >= 1 && j+1 <= z && k != 1) chmax(dp[i+1][j+1][1], dp[i][j][k] + a[pos-1]);
				}
			}
		}
		llint ans = 0;
		for(int i = 0; i <= z; i++){
			for(int j = 0; j < 2; j++){
				ans = max(ans, dp[K][i][j]);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}