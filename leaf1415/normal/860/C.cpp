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
typedef pair<string, string> P;

ll n;
string s[100005];
ll t[100005];
vector<P> ans;
set<string> S[2];
set<string> freeS[2];
set<string> wrong[2];

ll check(string &s)
{
	for(auto c : s)
	{
		if(c < '0' || c > '9') return -1;
	}
	if(s.front() == '0') return -1;
	return atoi(s.c_str());
}
string tostr(ll x)
{
	string ret;
	for(;x;x/=10) ret += x%10+'0';
	reverse(all(ret));
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> s[i] >> t[i];
	
	ll e = 0;
	rep(i, 1, n) e += t[i];
	rep(i, 1, e) S[1].insert(tostr(i));
	rep(i, e+1, n) S[0].insert(tostr(i));
	
	rep(i, 1, n){
		ll res = check(s[i]);
		if(res == -1 || res > n){
			freeS[t[i]].insert(s[i]);
			continue;
		}
		
		if(res <= e) S[1].erase(s[i]);
		else S[0].erase(s[i]);
		
		if(res > e && t[i] == 1) wrong[t[i]].insert(s[i]);
		else if(res <= e && t[i] == 0) wrong[t[i]].insert(s[i]);
	}
	
	if((wrong[0].size() || wrong[1].size()) && S[0].size() == 0 && S[1].size() == 0){
		string str = *wrong[0].begin();
		S[1].insert(str.c_str());
		wrong[0].erase(str);
		ans.push_back(P(str, "unko"));
		str = "unko";
		freeS[0].insert(str);
	}
	
	
	while(wrong[0].size() || wrong[1].size()){
		rep(i, 0, 1){
			if(wrong[i].size() && S[i].size()){
				string str = *wrong[i].begin(), nstr = *S[i].begin();
				S[1-i].insert(str.c_str());
				wrong[i].erase(str);
				ans.push_back(P(str, nstr));
				S[i].erase(nstr);
			}
		}
	}
	rep(i, 0, 1){
		while(freeS[i].size()){
			string str = *freeS[i].begin(), nstr = *S[i].begin();
			freeS[i].erase(str);
			ans.push_back(P(str, nstr));
			S[i].erase(nstr);
		}
	}
	
	cout << ans.size() << endl;
	for(auto p : ans) cout << "move " << p.first << " " << p.second << endl;
	
	return 0;
}