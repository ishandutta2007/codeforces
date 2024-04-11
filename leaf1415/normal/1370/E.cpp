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
string s, t;
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s >> t;
	
	string ss = s, tt = t;
	sort(ss.begin(), ss.end());
	sort(tt.begin(), tt.end());
	
	if(ss != tt){
		cout << -1 << endl;
		return 0;
	}
	
	string tmp;
	for(int i = 0; i < n; i++){
		if(s[i] != t[i]) tmp += s[i];
	}
	s = tmp;
	
	if(s.size() == 0){
		cout << 0 << endl;
		return 0;
	}
	
	llint cnt = 1, id = 0;
	for(int i = 1; i < s.size(); i++){
		if(s[i] == s[i-1]) cnt++;
		else{
			mp[id++] = cnt;
			cnt = 1;
		}
	}
	if(cnt > 0) mp[id] = cnt;
	
	llint ans = 0;
	while(mp.size()){
		ans++;
		
		//for(auto it = mp.begin(); it != mp.end(); it++) cout << it->second << " ";
		//cout << endl;
		
		for(auto it = mp.begin(); it != mp.end(); it++){
			auto suc = it; suc++;
			if(suc != mp.end()) it->second--;
			else{
				if(mp.size() % 2 == 0) it->second--;
			}
		}
		
		//for(auto it = mp.begin(); it != mp.end(); it++) cout << it->second << " ";
		//cout << endl;
		
		for(auto it = mp.begin(); it != mp.end();){
			if(it->second == 0){
				auto cur = it;
				auto suc = it; suc++;
				if(it != mp.begin() && suc != mp.end()){
					it--;
					it->second += suc->second;
					mp.erase(suc);
					mp.erase(cur);
					it++;
				}
				else{
					it++;
					mp.erase(cur);
				}
			}
			else it++;
		}
	}
	cout << ans << endl;
	
	return 0;
}