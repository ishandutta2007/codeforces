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
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n;
llint dp[2000005];
bool flag[2000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	dp[3] = dp[4] = 1;
	flag[3] = true;
	for(int i = 5; i < 2000005; i++){
		dp[i] = dp[i-2] * 2 % mod + dp[i-1], dp[i] %= mod;
		if(!flag[i-2] && !flag[i-1]){
			dp[i]++, dp[i] %= mod;
			flag[i] = true;
		}
	}
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		cout << (dp[n]*4) % mod << endl;
	}
	
	return 0;
}