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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll Q;
bool b[26];
string s;
string pre, suf;

bool check(string s, string t)
{
	rep(i, 0, (int)s.size()-1){
		if(t[i] == '?'){
			if(!b[s[i]-'a']) return false;
		}
		else{
			if(s[i] != t[i]) return false;
		}
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	for(auto c : s) b[c-'a'] = true;
	cin >> s;

	ll p = s.size(); bool flag = false;
	rep(i, 0, s.size()-1){
		if(s[i] == '*') p = i, flag = true;
	}
	pre = s.substr(0, p);
	if(p < (int)s.size()-1) suf = s.substr(p+1);

	//cout << pre << " " << suf << endl;


	cin >> Q;
	rep(q, 1, Q){
		cin >> s;
		if(!flag && s.size() != (int)pre.size()){
			cout << "NO" << "\n";
			continue;
		}
		if((int)s.size() < (int)pre.size() + (int)suf.size()){
			cout << "NO" << "\n";
			continue;
		}
		string S, T;
		if(pre.size()) S = s.substr(0, (int)pre.size());
		if(suf.size()) T = s.substr((int)s.size()-(int)suf.size());
		if(!check(S, pre) || !check(T, suf)){
			cout << "NO" << "\n";
			continue;
		}
		bool flag = true;
		rep(i, (int)pre.size(), (int)s.size() - (int)suf.size() - 1){
			if(b[s[i]-'a']) flag = false;
		}
		if(flag) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	flush(cout);

	return 0;
}