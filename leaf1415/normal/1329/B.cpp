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
llint x, mod;
llint beki[35];
llint dp[35];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> x >> mod;
		
		llint n = 0;
		for(llint t = x; t; t/=2) n++;
		llint r = x-(1<<(n-1))+1; r %= mod;
		
		beki[0] = 1;
		for(int i = 1; i < 35; i++) beki[i] = beki[i-1] * 2 % mod;
		
		for(int i = 0; i <= n; i++) dp[i] = 0;
		dp[0] = 1;
		for(int i = 0; i < n; i++){
			for(int j = i+1; j <= n; j++){
				if(j == n) dp[j] += dp[i] * r % mod, dp[j] %= mod;
				else dp[j] += dp[i] * beki[j-1] % mod, dp[j] %= mod;
			}
		}
		llint ans = 0;
		for(int i = 1; i <= n; i++) ans += dp[i], ans %= mod;
		cout << ans << endl;
	}
	
	return 0;
}