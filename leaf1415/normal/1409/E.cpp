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
llint n, k;
vector<llint> vec;
llint dp[200005][3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		llint x;
		vec.clear();
		for(int i = 1; i <= n; i++){
			cin >> x;
			vec.push_back(x);
		}
		for(int i = 1; i <= n; i++) cin >> x;
		sort(vec.begin(), vec.end());
		
		llint m = vec.size();
		for(int i = 0; i <= m; i++){
			for(int j = 0; j <= 2; j++){
				dp[i][j] = -inf;
			}
		}
		dp[0][0] = 0;
		
		for(int i = 0; i < m; i++){
			llint p = upper_bound(vec.begin(), vec.end(), vec[i]+k) - vec.begin();
			for(int j = 0; j <= 2; j++){
				chmax(dp[i+1][j], dp[i][j]);
				if(j+1 <= 2) chmax(dp[p][j+1], dp[i][j]+(p-i));
			}
		}
		
		llint ans = 0;
		for(int i = 0; i <= 2; i++) ans = max(ans, dp[m][i]);
		cout << ans << endl;
	}
	
	return 0;
}