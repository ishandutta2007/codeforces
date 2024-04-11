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

llint x, y, z;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x >> y >> z;
	
	llint ans = 0;
	if((x+y)/z != x/z+y/z){
		ans = min(x%z, z-x%z);
		ans = min(ans, min(y%z, z-y%z));
	}
	cout << (x+y)/z << " " << ans << endl;
	
	return 0;
}