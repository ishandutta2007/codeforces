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
typedef pair<llint, llint> P;

llint a, b, x;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> x;
	string s, t;
	rep(i, 1, a) s += '0';
	rep(i, 1, b) t += '1';
	
	if(s.size() < t.size()) swap(s, t);
	if(x == 1){
		cout << s + t << endl;
		return 0;
	}
	string ans;
	llint rem = x+1;
	while(rem >= 2){
		if(rem % 2 == 0) ans += t.back(), t.pop_back();
		else ans += s.back(), s.pop_back();
		rem--;
	}
	ans += t + s;
	cout << ans << endl;
	
	return 0;
}