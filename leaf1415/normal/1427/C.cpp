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

int n, r;
int t[100005], x[100005], y[100005];
int dp[100005], maxdp[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> n;
	for(int i = 1; i <= n; i++) cin >> t[i] >> x[i] >> y[i];
	x[0] = y[0] = 1;
	
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		dp[i] = -1e9;
		for(int j = i-1; j >= 0; j--){
			if(t[j] <= t[i] - 1000){
				chmax(dp[i], maxdp[j]+1);
				break;
			}
			if(abs(x[i]-x[j])+abs(y[i]-y[j]) <= t[i]-t[j]) chmax(dp[i], dp[j]+1);
		}
		maxdp[i] = max(maxdp[i-1], dp[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans << endl;
	
	return 0;
}