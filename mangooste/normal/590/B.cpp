#include <bits/stdc++.h>

using namespace std;

struct point {
	double x, y;
	point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	point operator + (point v) {
		return point(x + v.x, y + v.y);
	}
	point operator * (double k) {
		return point(x * k, y * k);
	}
};

double dist(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

signed main() {
	point s, f;
	cin >> s.x >> s.y >> f.x >> f.y;
	double vmax, t;
	cin >> vmax >> t;
	point v1, v2;
	cin >> v1.x >> v1.y >> v2.x >> v2.y;
	v1 = v1 * -1.0, v2 = v2 * -1.0;
	double L = 0.0, R = 1e9;
	for (int i = 0; i < 1000; i++) {
		double mid = (L + R) / 2;
		(dist(s, f + v1 * min(mid, t) + v2 * max(0.0, mid - t)) > mid * vmax ? L : R) = mid;
	}
	cout << fixed << setprecision(15) << R;
}