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
llint p[4005];
vector<llint> vec;
llint dp[4005][2005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> n;
		for(int i = 1; i <= 2*n; i++) cin >> p[i];
		p[2*n+1] = 2*n+1;
		
		vec.clear();
		llint l = 1, mx = p[1];
		for(int i = 2; i <= 2*n+1; i++){
			if(mx < p[i]){
				vec.push_back(i-l);
				mx = p[i];
				l = i;
			}
		}
		
		llint m = vec.size();
		for(int i = 0; i <= m; i++){
			for(int j = 0; j <= n; j++){
				dp[i][j] = false;
			}
		}
		dp[0][0] = true;
		
		for(int i = 0; i < m; i++){
			llint x = vec[i];
			for(int j = 0; j <= n; j++){
				dp[i+1][j] |= dp[i][j];
				if(j+x <= n) dp[i+1][j+x] |= dp[i][j];
			}
		}
		if(dp[m][n]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}