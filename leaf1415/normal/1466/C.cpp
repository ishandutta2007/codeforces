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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll T;
ll n;
string s;
ll dp[100005][2][3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> s;
		ll n = s.size();
		s = "#" + s;
		
		rep(i, 0, n) rep(j, 0, 1) rep(k, 0, 1) dp[i][j][k] = inf;
		dp[0][0][0] = 0;
		
		rep(i, 0, n-1){
			rep(j, 0, 1){
				rep(k, 0, 1){
					if(!(i >= 1 && j == 0 && s[i+1] == s[i]) && !(i-1 >= 1 && k == 0 && s[i+1] == s[i-1])){
						chmin(dp[i+1][0][j], dp[i][j][k]);
					}
					chmin(dp[i+1][1][j], dp[i][j][k]+1);
				}
			}
		}
		
		ll ans = inf;
		rep(j, 0, 1) rep(k, 0, 1) chmin(ans, dp[n][j][k]);
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}