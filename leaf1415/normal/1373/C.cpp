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
set<llint> S;
vector<llint> vec[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		llint n = s.size();
		s = "#" + s;
		
		S.clear();
		for(int i = 0; i <= n+1; i++) vec[i].clear();
		
		llint cur = 0;
		for(int i = 1; i <= n; i++){
			if(s[i] == '+') cur++;
			else cur--;
			if(cur < 0){
				S.insert(i);
				vec[-cur].push_back(i);
			}
		}
		
		llint ans = 0;
		for(int i = 1; i <= n+1; i++){
			if(S.size() == 0){
				ans += n;
				break;
			}
			ans += *S.begin();
			for(int j = 0; j < vec[i].size(); j++) S.erase(vec[i][j]);
		}
		cout << ans << endl;
	}
	
	return 0;
}