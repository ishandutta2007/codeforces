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

llint T;
llint n;
llint t[205];
llint dp[205][605];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> t[i];
		sort(t+1, t+n+1);
		
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= 3*n; j++){
				dp[i][j] = inf;
			}
		}
		dp[0][0] = 0;
		
		for(int i = 0; i <= n; i++){
			for(int j = 0; j < 3*n; j++){
				chmin(dp[i][j+1], dp[i][j]);
				if(i+1 <= n) chmin(dp[i+1][j+1], dp[i][j]+abs((j+1)-t[i+1]));
			}
		}
		cout << dp[n][3*n] << endl;
	}
	
	return 0;
}