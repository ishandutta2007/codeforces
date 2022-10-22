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
//#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353

#define inf 1e9

using namespace std;
typedef pair<llint, llint> P;

string s, t;
int succ[10005];
int dp[10005][10005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> t;
	int S = s.size(), T = t.size();
	s = "#" + s, t = "#" + t;
	
	for(int i = 0; i <= S; i++){
		succ[i] = -1;
		llint h = 0;
		for(int j = i+1; j <= S; j++){
			if(s[j] == '.') h--;
			else h++;
			if(h == 0){
				succ[i] = j;
				break;
			}
			if(h < 0) break;
		}
	}
	
	for(int i = 0; i <= T; i++){
		for(int j = 0; j <= S; j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	
	for(int i = 0; i <= T; i++){
		for(int j = 0; j <= S; j++){
			if(i+1 <= T && j+1 <= S && s[j+1] == t[i+1]) chmin(dp[i+1][j+1], dp[i][j]);
			if(succ[j] != -1) chmin(dp[i][succ[j]], dp[i][j]);
			if(j+1 <= S) chmin(dp[i][j+1], dp[i][j]+1);
		}
	}
	cout << dp[T][S] << endl;
	
	return 0;
}