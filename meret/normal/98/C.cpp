#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

typedef long double LD;

struct Point {
	LD x, y;
	Point (LD _x, LD _y) :x(_x), y(_y) {}
};

LD det(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int a, b, l;

LD check(LD angle) {
	LD x = cosl(angle) * l;
	LD y = sinl(angle) * l;
	Point p1(x, 0);
	Point p2(0, y);
	return -det(p1, p2, Point(b, a));
}

int main() {
	scanf("%d %d %d", &a, &b, &l);
	LD pi = 2 * acosl(0);
	LD left = 0, right = pi / 2;
	for (int i = 0; i < 100; ++i) {
		LD cl = left + (right - left) / 3.0;
		LD cr = left + 2 * (right - left) / 3.0;
		if (check(cl) > check(cr))
			left = cl;
		else
			right = cr;
	}
	LD result = check(left) / l;
	if (l <= max(a, b))
		result = max(result, (LD) min(a, b));
	if (result < 0)
		printf("My poor head =(\n");
	else
		printf("%.9lf\n", (double) min(LD(l), result));
}