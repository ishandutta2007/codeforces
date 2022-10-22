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
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		reverse(s.begin(), s.end());
		llint n = s.size();
		
		string u;
		for(int i = 0; i < n; i++){
			if(s[i] == 'B') u += s[i];
			else if(u.size() && u.back() == 'B') u.pop_back();
			else u += s[i];
		}
		while(u.size() >= 2 && u.substr((int)u.size()-2, 2) == "BB"){
			u.pop_back(), u.pop_back();
		}
		cout << u.size() << endl;
	}
	
	return 0;
}