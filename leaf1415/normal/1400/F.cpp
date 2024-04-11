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

string s;
llint x;
llint mp[1<<20];
vector<llint> vec;
llint trans[1<<20][10];
llint dp[1005][12005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	llint n = s.size();
	s = "#" + s;
	
	cin >> x;
	
	if(x == 1){
		llint ans = 0;
		for(int i = 1; i <= n; i++){
			if(s[i] == '1') ans++;
		}
		cout << ans << endl;
		return 0;
	}
	
	
	llint X = 1<<x;
	for(int i = 0; i < X; i++){
		mp[i] = -1;
		if(!(i & 1)) continue;
		for(int d = 1; d < x; d++){
			if(x % d) continue;
			for(int j = 0; j < x; j++){
				if((i & (1<<j)) && (i & (1<<(j+d)))) goto pass;
			}
		}
		vec.push_back(i);
		mp[i] = (int)vec.size()-1;
		pass:;
	}
	llint m = vec.size();
	
	
	for(int i = 0; i < m; i++){
		for(int j = 1; j <= 9; j++){
			llint b = vec[i];
			b <<= j;
			for(int d = 1; d < x; d++){
				if(x % d) continue;
				if(b & (1<<d)){
					b %= (1<<d);
					break;
				}
			}
			if(b & (1<<x)){
				trans[i][j] = -1;
				continue;
			}
			b %= X;
			b |= 1;
			trans[i][j] = mp[b];
		}
	}
	
	/*for(int i = 0; i < vec.size(); i++){
		cout << bitset<8>(vec[i]);
		cout << "->" << endl;
		for(int j = 1; j <= 9; j++){
			if(trans[i][j] != -1)
			cout << j << " " << bitset<8>(vec[trans[i][j]]) << endl;
		}
	}*/
	
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < m; j++){
			dp[i][j] = inf;
		}
	}
	dp[0][mp[1]] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			chmin(dp[i+1][j], dp[i][j] + 1);
			if(trans[j][s[i+1]-'0'] != -1) chmin(dp[i+1][trans[j][s[i+1]-'0']], dp[i][j]);
		}
	}
	
	/*for(int i = 0; i <= n; i++){
		for(int j = 0; j < m; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	llint ans = inf;
	for(int j = 0; j < m; j++) ans = min(ans, dp[n][j]);
	cout << ans << endl;
	
	return 0;
}