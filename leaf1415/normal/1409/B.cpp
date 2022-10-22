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
llint a, b, x, y, n;

llint calc(llint a, llint b, llint x, llint y, llint n)
{
	llint t = min(a-x, n);
	a -= t, n -= t;
	
	t = min(b-y, n);
	b -= t, n -= t;
	
	return a * b;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t <T; t++){
		cin >> a >> b >> x >> y >> n;
		llint ans = min(calc(a, b, x, y, n), calc(b, a, y, x, n));
		cout << ans << endl;
	}
	
	return 0;
}