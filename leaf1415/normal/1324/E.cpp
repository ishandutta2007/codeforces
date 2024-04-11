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
#define llint long long
#define inf 1e18

using namespace std;

llint n, h, l, r;
llint a[2005];
llint dp[2005][2005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> h >> l >> r;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < h; j++){
			dp[i][j]= -inf;
		}
	}
	dp[0][0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < h; j++){
			for(int k = -1; k <= 0; k++){
				llint nj = (a[i+1]+j+k) % h;
				llint cost = 0;
				if(nj >= l && nj <= r) cost++;
				dp[i+1][nj] = max(dp[i+1][nj], dp[i][j] + cost);
			}
		}
	}
	llint ans = 0;
	for(int i = 0; i < h; i++) ans = max(ans, dp[n][i]);
	cout << ans << endl;
	
	return 0;
}