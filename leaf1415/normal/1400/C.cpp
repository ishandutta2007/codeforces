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
string s;
llint x;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> s >> x;
		
		string ans = s;
		for(int i = 0; i < ans.size(); i++){
			if((i-x < 0 || s[i-x] == '1') && (i+x >= s.size() || s[i+x] == '1')) ans[i] = '1';
			else ans[i] = '0';
		}
		
		string t;
		for(int i = 0; i < ans.size(); i++){
			if(i-x >= 0 && ans[i-x] == '1') t += '1';
			else if(i+x < ans.size() && ans[i+x] == '1') t += '1';
			else t += '0';
		}
		if(s != t) cout << -1 << endl;
		else cout << ans << endl;
	}
	
	return 0;
}