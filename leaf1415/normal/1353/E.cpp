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
llint n, k;
string s, tmp;
llint dp[1000005][3];

llint calc()
{
	llint m = tmp.size();
	for(int i = 0; i <= m; i++){
		for(int j = 0; j < 3; j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				if(k < j) continue;
				llint cost = 0;
				if(tmp[i]%2 != k%2) cost = 1;
				chmin(dp[i+1][k], dp[i][j] + cost);
			}
		}
	}
	llint ret = inf;
	for(int j = 0; j < 3; j++) ret = min(ret, dp[m][j]);
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		cin >> s;
		
		llint sum = 0;
		for(int i = 0; i < s.size(); i++) sum += s[i]%2;
		
		llint ans = inf;
		for(int i = 0; i < k; i++){
			tmp = "";
			llint one = 0;
			for(int j = i; j < s.size(); j+=k){
				tmp += s[j];
				one += s[j]%2;
			}
			ans = min(ans, sum - one + calc());
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}