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

string s, t;
ll cnt[27];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> t;
	for(auto c : s){
		if(c == '?') cnt[26]++;
		else cnt[c-'a']++;
	}
	
	
	string ans;
	while(1){
		for(auto c : t){
			if(cnt[c-'a']) cnt[c-'a']--;
			else if(cnt[26]) cnt[26]--, ans += c;
			else goto end;
		}
	}
	end:;
	rep(j, 1, cnt[26]) ans += 'z';
	
	ll p = 0;
	for(auto &c : s){
		if(c == '?') c = ans[p], p++;
	}
	cout << s << endl;
	
	return 0;
}