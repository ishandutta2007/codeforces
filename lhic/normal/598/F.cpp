#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef double ld;

using namespace std;

int sgn(ll x) {
	return x > 0 ? 1 : (x < 0 ? -1 : 0);
}

struct point {
	ll x, y;
	point() { x = y = 0; }
	point(ll x, ll y) : x(x), y(y) {}
	point operator-(point a) { return point(x - a.x, y - a.y); }
	ll operator*(point a) { return x * a.y - y * a.x; }
	ll operator^(point a) { return x * a.x + y * a.y; };
};

struct pointd {
	ld x, y;
	pointd() { x = y = 0; }
	pointd(ld x, ld y) : x(x), y(y) {}
	pointd(point a) : x(a.x), y(a.y) {}
	pointd operator-(pointd a) { return pointd(x - a.x, y - a.y); }
	ld operator*(pointd a) { return x * a.y - y * a.x; }
	ld operator^(pointd a) { return x * a.x + y * a.y; };
};

struct line {
	ll a, b, c;
	line(point x, point y) {
		a = x.y - y.y;
		b = y.x - x.x;
		c = -(a * x.x + b * x.y);
	}
	ll operator()(point x) {
		return x.x * a + x.y * b + c;
	}
};

pointd cross(line a, line b) {
	ld d = a.a / 100.0 * b.b / 100.0 - a.b / 100.0 * b.a / 100.0;
	ld dx = a.c / 100.0 * b.b / 100.0 - a.b / 100.0 * b.c / 100.0;
	ld dy = a.a / 100.0 * b.c / 100.0 - a.c / 100.0 * b.a / 100.0;
	pointd ans;
	ans.x = -dx / d;
	ans.y = -dy / d;
	return ans;
}

vector<pointd> vv;
vector<ld> vv2;
point arr[3000];
int n;

ld solve(point p1, point p2) {
	line l = line(p1, p2);
	vv.clear();
	for (int i = 0; i < n; ++i) {
		if (l(arr[i]) == 0 || l(arr[i + 1]) == 0)
			continue;
		if ((l(arr[i]) < 0 && l(arr[i + 1]) < 0) || (l(arr[i]) > 0 && l(arr[i + 1]) > 0))
			continue;
		vv.push_back(cross(l, line(arr[i], arr[i + 1])));
	}
	for (int i = 1; i <= n; ++i) {
		if (l(arr[i]) != 0)
			continue;
		if (sgn(l(arr[i - 1])) == sgn(l(arr[i + 1])))
			continue;
		if (l(arr[i - 1]) == 0) {
			if ((arr[i + 1] - arr[i]) * (arr[i] - arr[i - 1]) < 0)
				vv.push_back(arr[i]);
		}
		else if (l(arr[i + 1]) == 0) {
			if ((arr[i + 1] - arr[i]) * (arr[i] - arr[i - 1]) < 0)
				vv.push_back(arr[i]);
		}
		else
			vv.push_back(arr[i]);
	}
	vv2.clear();
	pointd xx = p2 - p1;
	ld dd = sqrt(xx.x * xx.x + xx.y * xx.y);
	for (int i = 0; i < (int)vv.size(); ++i)
		vv2.push_back((xx ^ vv[i]) / dd);
	sort(vv2.begin(), vv2.end());
	ld ans = 0;
	for (int i = 0; i < (int)vv2.size(); i += 2)
		ans += vv2[i + 1] - vv2[i];
	ans /= 100;
	return ans;
}

void read(ll &x, ll &y) {
	ld x1, y1;
	scanf("%lf%lf", &x1, &y1);
	x1 *= 100;
	y1 *= 100;
	x = lround(x1);
	y = lround(y1);
}

int main() {
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		read(arr[i].x, arr[i].y);
	}
	arr[n] = arr[0];
	arr[n + 1] = arr[1];
	ll total = 0;
	for (int i = 0; i < n; ++i)
		total += arr[i] * arr[i + 1];
	if (total < 0)
		reverse(arr, arr + n + 2);

	for (int i = 0; i < m; ++i) {
		point p1, p2;
		read(p1.x, p1.y);
		read(p2.x, p2.y);
		printf("%.9lf\n", solve(p1, p2));
	}
	return 0;
}