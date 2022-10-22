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
llint n;
string s, t;
llint dp[2005][2005];
llint sumS[2005][26], sumT[2005][26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> n;
		cin >> s >> t;
		string S = s, T = t;
		sort(S.begin(), S.end());
		sort(T.begin(), T.end());
		if(S != T){
			cout << -1 << endl;
			continue;
		}
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		s = "#" + s, t = "#" + t;
		
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < 26; j++){
				sumS[i][j] = sumS[i-1][j];
				sumT[i][j] = sumT[i-1][j];
			}
			sumS[i][s[i]-'a']++;
			sumT[i][t[i]-'a']++;
		}
		
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				dp[i][j] = inf;
			}
		}
		dp[0][0] = 0;
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				if(i+1 <= n && j+1 <= n && t[i+1] == s[j+1]) chmin(dp[i+1][j+1], dp[i][j]);
				if(j+1 <= n) chmin(dp[i][j+1], dp[i][j]+1);
				if(i+1 <= n && sumT[i][t[i+1]-'a'] < sumS[j][t[i+1]-'a']) chmin(dp[i+1][j], dp[i][j]);
			}
		}
		cout << dp[n][n] << endl;
	}
	
	return 0;
}