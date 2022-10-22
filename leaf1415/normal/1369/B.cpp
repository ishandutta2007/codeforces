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

llint T;
llint n;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		cin >> s;
		llint l = inf, r = -inf;
		for(llint i = 0; i < s.size(); i++){
			if(s[i] == '1') l = min(l, i);
			else r = max(r, i);
		}
		if(l > r) cout << s << endl;
		else{
			for(int i = 0; i < l; i++) cout << 0;
			cout << 0;
			for(int i = r+1; i < s.size(); i++) cout << 1;
			cout << endl;
		}
	}
	
	return 0;
}