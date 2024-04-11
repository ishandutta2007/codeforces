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
llint a, b;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> a >> b;
		llint ans = max(2*a, b);
		ans = min(ans, max(2*b, a));
		ans = min(ans, max(a+b, max(a, b)));
		cout << ans*ans << endl;
	}
	
	return 0;
}