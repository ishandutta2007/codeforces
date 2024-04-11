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
//#define inf 1e18
#define inf 1e9

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint S, T;
string s, t;
int dp[5005][5005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> S >> T;
	cin >> s >> t;
	s = "#" + s, t = "#" + t;
	
	rep(i, 1, S){
		rep(j, 1, T){
			dp[i][j] = -inf;
		}
	}
	rep(i, 1, S){
		rep(j, 1, T){
			if(s[i] == t[j]){
				chmax(dp[i][j], dp[i-1][j-1] + 2);
				chmax(dp[i][j], 2);
			}
			chmax(dp[i][j], dp[i-1][j] - 1);
			chmax(dp[i][j], dp[i][j-1] - 1);
		}
	}
	int ans = 0;
	rep(i, 1, S){
		rep(j, 1, T){
			chmax(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	
	return 0;
}