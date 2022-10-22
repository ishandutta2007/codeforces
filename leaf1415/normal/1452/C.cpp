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

ll T;
string s;
stack<char> stk;

ll calc(string s)
{
	while(stk.size()) stk.pop();
	
	ll ans = 0;
	for(auto c : s){
		if(c == ')' && stk.size() && stk.top() == '('){
			stk.pop();
			ans++;
		}
		else if(c == ']' && stk.size() && stk.top() == '['){
			stk.pop();
			ans++;
		}
		else stk.push(c);
	}
	return ans;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> s;
		
		string t, u;
		for(auto c : s){
			if(c == '(' || c == ')') t += c;
			else u += c;
		}
		ll ans = calc(t) + calc(u);
		
		cout << ans << endl;
	}
	
	return 0;
}