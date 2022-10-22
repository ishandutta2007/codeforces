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

llint n;
string s;
set<llint> S;
llint pos;
llint ans[1000005];
vector<llint> vec[1000005];
llint succ[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s;
	s = "#" + s + "#";
	
	llint l = -1;
	for(int i = 1; i <= n+1; i++){
		if(s[i] == '?'){
			if(l == -1) l = i;
		}else{
			if(l == -1) continue;
			if(s[l-1] == '#' && s[i] == '#'){
				for(int j = 1; j <= n; j++) cout << n/j << " "; cout << endl;
				return 0;
			}
			if(s[l-1] == '#' || s[i] == '#' || s[l-1] == s[i]){
				char c = s[i];
				if(s[i] == '#') c = s[l-1];
				for(int j = l; j <= i-1; j++) s[j] = c;
			}
			l = -1;
		}
	}
	
	succ[n+1] = n+1;
	for(int i = n; i >= 0; i--){
		succ[i] = succ[i+1];
		if(s[i] != s[i+1]) succ[i] = i+1;
	}
	
	for(int i = 1; i <= n; i++) S.insert(i);
	
	
	for(int i = 0; i <= n-1; i++){
		
		llint lim, dest, r = succ[i+1];
		if(s[i+1]  == '?') r = succ[r];
		if(s[r] != '?') lim = dest = r-1;
		else dest = r-1, lim = succ[r]-1;
		
		if(i == pos){
			for(int j = 0; j < vec[i].size(); j++) S.insert(vec[i][j]);
			for(auto it = S.begin(); it != S.end();){
				auto tmp = it;
				it++;
				if(i + *tmp <= lim){
					vec[i+*tmp].push_back(*tmp);
					ans[*tmp]++;
					S.erase(tmp);
				}
				else break;
			}
			pos = dest;
		}
		else{
			for(int j = 0; j < vec[i].size(); j++){
				if(i + vec[i][j] <= lim){
					vec[i+vec[i][j]].push_back(vec[i][j]);
					ans[vec[i][j]]++;
				}
				else vec[dest].push_back(vec[i][j]);
			}
		}
	}
	
	for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}