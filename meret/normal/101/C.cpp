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

#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)

typedef long double LDB;

struct Vector {
	int x, y;

	Vector (int _x = 0, int _y = 0) {
		x = _x;
		y = _y;
	}

	void read() {
		scanf("%d %d", &x, &y);
	}
};

bool is0(LDB x) {
	return -1e-9 < x && x < 1e-9;
}

bool check(int a, int b, int xx, int yy) {
	if (a == 0 && b == 0 && (xx != 0 || yy != 0))
		return false;
	if (a == 0 && b == 0 && xx == 0 && yy == 0)
		return true;
	long double x, y;
	if (a != 0) {
		// a * x + b * y == xx;
		// b * y - (b * b / a) * x == yy;
		x = (xx - (LDB(b) / LDB(a)) * yy) / (a + LDB(b) * LDB(b) / LDB(a));
		y = (yy + b * x) / LDB(a);
	} else {
		x = (yy - (LDB(a) / LDB(b)) * xx) / (-b - LDB(a) * LDB(a) / LDB(b));
		y = (xx - a * x) / LDB(b);
	}

	return is0(roundl(x) - x) && is0(roundl(y) - y);
}

// a * x + b * y = xx;
// a * y - b * x = yy;

Vector rot(Vector v) {
	return Vector(v.y, -v.x);
}

int main() {
	Vector a, b, c;
	a.read();
	b.read();
	c.read();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (check(c.x, c.y, b.x - a.x, a.y - b.y)) {
				printf("YES\n");
				return 0;
			}
			c = rot(c);
		}
		a = rot(a);
	}
	printf("NO\n");
}