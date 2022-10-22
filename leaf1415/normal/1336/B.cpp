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
#define inf 4e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint s[3];
vector<llint> vec[3];

llint calc(llint l, llint m, llint r)
{
	llint ret = inf;
	for(int i = 0; i < vec[m].size(); i++){
		llint x = vec[m][i];
		auto it = lower_bound(vec[r].begin(), vec[r].end(), x);
		if(it == vec[r].end()) continue;
		
		llint y = *it;
		it = upper_bound(vec[l].begin(), vec[l].end(), x);
		if(it == vec[l].begin()) continue;
		it--;
		
		llint z = *it;
		chmin(ret, (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x));
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		
		cin >> s[0] >> s[1] >> s[2];
		for(int i = 0; i < 3; i++){
			vec[i].clear();
			llint x;
			for(int j = 0; j < s[i]; j++){
				cin >> x;
				vec[i].push_back(x);
			}
			sort(vec[i].begin(), vec[i].end());
		}
		
		llint ans = inf;
		chmin(ans, calc(0, 1, 2));
		chmin(ans, calc(0, 2, 1));
		chmin(ans, calc(1, 0, 2));
		chmin(ans, calc(1, 2, 0));
		chmin(ans, calc(2, 0, 1));
		chmin(ans, calc(2, 1, 0));
		cout << ans << endl;
	}
	
	return 0;
}