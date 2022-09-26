#include <bits/stdc++.h>
using namespace std;

struct point {
	int x, y;
	point(int x = 0,int y = 0) : x(x), y(y) {}
	point operator - (const point &p) {
		return point(x - p.x, y - p.y);
	}
	bool operator < (const point &p) {
		return make_pair(y, x) < make_pair(p.y, p.x);
	}
};

point pivot = point();

long long cross(point a,point b) {
	return 1ll * a.x * b.y - 1ll * b.x * a.y;
}

bool cmp(point a,point b) {
	bool fa = a < pivot;
	bool fb = b < pivot;
	if (fa ^ fb) return fb;
	return cross(a, b) > 0;
}

const int N = 2005;

int n;
point p[N];

long long func(int x) {
	int y = n - 2 - x;
	return 1ll * (x * (x - 1) / 2) * (y * (y - 1) / 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;
	long long ans = 0;
	for (int root = 1; root <= n; ++root) {
		vector<point> pts;
		for (int i = 1; i <= n; ++i) if (i != root) {
			pts.push_back(p[i] - p[root]);
		}
		sort(pts.begin(), pts.end(), cmp);
		for (int i = 0; i < n - 1; ++i) pts.push_back(pts[i]);
		int ptr = 0;
		for (int i = 0; i < n - 1; ++i) {
			ptr = max(ptr, i);
			while (ptr < i + n - 1 && cross(pts[i], pts[ptr]) >= 0) ptr++;
			ans += func(ptr - i - 1);
		}
	}
	cout << ans / 2 << '\n';
}