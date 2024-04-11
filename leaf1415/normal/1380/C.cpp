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
llint n, x;
llint a[100005], dp[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> x;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1, a+n+1);
		
		for(int i = 1; i <= n; i++) dp[i] = -inf;
		for(int i = 0; i < n; i++){
			dp[i+1] = max(dp[i+1], dp[i]);
			llint m = (x+a[i+1]-1) / a[i+1];
			if(i+m <= n) dp[i+m] = max(dp[i+m], dp[i]+1);
		}
		cout << dp[n] << endl;
	}
	
	return 0;
}