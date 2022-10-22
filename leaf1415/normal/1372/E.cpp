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
llint a[105][105], sum[105][105];
llint dp[105][105];

llint get(llint l, llint r)
{
	if(l > r) return 0;
	return sum[w][r] - sum[l-1][r];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	llint k, l, r;
	for(int i = 1; i <= h; i++){
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> l >> r;
			a[l][r]++;
		}
	}
	for(int i = 1; i <= w; i++){
		for(int j = 1; j <= w; j++){
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
		}
	}
	
	for(int len = 1; len <= w; len++){
		for(int l = 1; l+len-1 <= w; l++){
			llint r = l+len-1;
			for(int i = l; i <= r; i++){
				llint cost = get(l, r) - get(l, i-1) - get(i+1, r);
				if(cost == 0) continue;
				dp[l][r] = max(dp[l][r], dp[l][i-1] + dp[i+1][r] + cost*cost);
			}
		}
	}
	/*for(int i = 1; i <= w; i++){
		for(int j = 1; j <= w; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[1][w] << endl;
	
	return 0;
}