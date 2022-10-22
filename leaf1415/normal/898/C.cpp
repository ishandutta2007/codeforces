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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
map<string, vector<string> > mp;

bool check(string &s, string &t)
{
	if(s.size() > t.size()) return false;
	return t.substr(t.size() - s.size(), s.size()) == s;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	string s, t; ll x;
	rep(i, 1, n){
		cin >> s;
		cin >> x;
		rep(i, 1, x){
			cin >> t;
			mp[s].push_back(t);
		}
	}
	
	cout << mp.size() << endl;
	for(auto x : mp){
		cout << x.first << " ";
		vector<string> &vec = x.second, ans;
		
		sort(all(vec));
		vec.erase(unique(all(vec)), vec.end());
		
		rep(i, 0, (int)vec.size()-1){
			bool flag = true;
			rep(j, 0, (int)vec.size()-1){
				if(i == j) continue;
				if(check(vec[i], vec[j])) flag = false;
			}
			if(flag) ans.push_back(vec[i]);
		}
		cout << ans.size() << " ";
		for(auto s : ans) cout << s << " ";
		cout << endl;
	}
	
	return 0;
}