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

string s;
llint dp[1000005][2];
llint succ[2][1000005];
llint run[1000005];
llint rpos[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	llint n = s.size();
	s = "#" + s;
	
	bool flag = false;
	for(int i = 1; i <= n; i++){
		if(s[i] == '1') flag = true;
	}
	if(!flag){
		cout << n << endl;
		return 0;
	}
		
	llint cnt = 0;
	for(int i = 0; i <= n; i++){
		if(s[i] == '0') cnt++;
		else cnt = 0;
		run[i] = cnt;
	}
	
	llint nx = n+1;
	for(int i = 1; i <= n+2; i++) rpos[i] = n+1;
	for(int i = n; i >= 0; i--){
		succ[0][i] = rpos[run[i]+1];
		succ[1][i] = nx;
		if(s[i] == '1') nx = i;
		else rpos[run[i]] = i;
	}
	
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			if(succ[0][i] <= n){
				if(j == 1 || s[i+1] == '0') (dp[succ[0][i]][j] += dp[i][j]) %= mod;
			}
			if(succ[1][i] <= n) (dp[succ[1][i]][1] += dp[i][j]) %= mod;
		}
	}
	
	/*for(int i = 0; i <= n; i++) cout << succ[0][i] << " "; cout << endl;
	for(int i = 0; i <= n; i++) cout << succ[1][i] << " "; cout << endl;
	for(int i = 0; i <= n; i++) cout << run[i] << " "; cout << endl;
	*/
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == '1') ans += dp[i][1], ans %= mod;
		if(s[i] == '0' && run[i] <= run[n]) ans += dp[i][1], ans %= mod;
	}
	cout << ans << endl;
	//for(int i = 0; i <= n; i++) cout << dp[i] << " "; cout << endl;
	
	return 0;
}