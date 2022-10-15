#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)

struct Point {
	double x, y;
	Point operator - (const Point &a) const {
		return {x - a.x, y - a.y};
	}
	double len() {
		return sqrt(x * x + y * y);
	}
	double operator * (const Point &a) const {
		return x * a.y - y * a.x;
	}
	double operator ^ (const Point &a) const {
		return x * a.x + y * a.y;
	}
};

double ans = 1e10;

void solve(Point a, Point b, Point c) {
	b = b - a;
	c = c - a;
	double l = (b ^ c) / c.len();
	double x = abs((b * c) * (l / c.len()) / l);
	ans = min(ans, x / 2);
}



int n;
Point a[2333];

int main() {
	read(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		read(x); read(y);
		a[i] = {double(x), double(y)};
	}
	for (int i = 1; i <= n; i++) {
		solve(a[i - 1], a[i % n], a[(i + 1) % n]);
	//	solve(a[i % n], a[i - 1], a[(i + 1) % n]);
	//	solve(a[i - 1], a[(i + 1) % n], a[i % n]);
	}
	printf("%.7lf\n", ans);

	return 0;
}