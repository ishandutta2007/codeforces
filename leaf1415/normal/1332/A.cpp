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
llint l, r, d, u;
llint x, y, lx, rx, ly, ry;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> l >> r >> d >> u;
		cin >> x >> y >> lx >> ly >> rx >> ry;
		
		bool ans = true;
		llint nx = x - l + r, ny = y - d + u;
		if(nx < lx || nx > rx || ny < ly || ny > ry) ans = false;
		if(l+r > 0 && lx == rx) ans = false;
		if(u+d > 0 && ly == ry) ans = false;
		if(ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}