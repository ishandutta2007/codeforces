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

string add(string s, string t)
{
	string ret = "";
	llint len = max((int)s.size(), (int)t.size());
	while(s.size() < len) s += '0';
	while(t.size() < len) t += '0';
	
	llint c = 0;
	for(int i = 0; i < len; i++)
	{
		llint a = s[i]-'0', b = t[i]-'0';
		ret += ((a+b+c) % 10) + '0';
		c = (a+b+c) / 10;
	}
	if(c != 0) ret += c + '0';
	return ret;
}

string getmin(string s, string t)
{
	if(s.size() < t.size()) return s;
	if(s.size() > t.size()) return t;
	
	string S = s, T = t;
	reverse(S.begin(), S.end());
	reverse(T.begin(), T.end());
	if(S <= T) return s;
	else return t;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s;
	reverse(s.begin(), s.end());
	
	string ans;
	for(int i = 0; i <= n+5; i++) ans += '9';

	llint cnt = 3;
	for(int i = n/2; i >= 1; i--){
		if(cnt == 0) break;
		if(s[i-1] != '0'){
			string t = add(s.substr(0, i), s.substr(i));
			ans = getmin(ans, t);
			cnt--;
		}
	}
	cnt = 3;
	for(int i = n/2+1; i < n; i++){
		if(cnt == 0) break;
		if(s[i-1] != '0'){
			string t = add(s.substr(0, i), s.substr(i));
			ans = getmin(ans, t);
			cnt--;
		}
	}
	
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	
	return 0;
}