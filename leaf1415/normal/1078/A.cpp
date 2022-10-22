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

llint a, b, c;
llint sx, sy, tx, ty;

double get2(double sx, double sy, double tx, double ty)
{
	return sqrt((sx-tx)*(sx-tx) + (sy-ty)*(sy-ty));
}

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> a >> b >> c;
	cin >> sx >> sy >> tx >> ty;
	
	double ans = abs(sx-tx)+abs(sy-ty);
	if(a == 0 || b == 0){
		printf("%.11f\n", ans);
		return 0;
	}
	
	double x = -(double)b/a*sy-(double)c/a;
	double y = -(double)a/b*sx-(double)c/b;
	double X = -(double)b/a*ty-(double)c/a;
	double Y = -(double)a/b*tx-(double)c/b;
	
	chmin(ans, abs(sx-x) + get2(x, sy, X, ty) + abs(tx-X));
	chmin(ans, abs(sy-y) + get2(sx, y, X, ty) + abs(tx-X));
	chmin(ans, abs(sy-y) + get2(sx, y, tx, Y) + abs(ty-Y));
	chmin(ans, abs(sx-x) + get2(x, sy, tx, Y) + abs(ty-Y));
	
	printf("%.11f\n", ans);
	
	return 0;
}