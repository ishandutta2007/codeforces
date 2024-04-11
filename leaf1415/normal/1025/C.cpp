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

string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	llint n = s.size();
	s = s + s + s;
	
	llint ans = 1, cnt = 1;
	rep(i, 1, (int)s.size()-1){
		if(s[i] != s[i-1]) cnt++;
		else cnt = 1;
		chmax(ans, cnt);
	}
	chmin(ans, n);
	
	cout << ans << endl;
	
	return 0;
}