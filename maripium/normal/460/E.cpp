#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
	Point(int x = 0,int y = 0) : x(x), y(y) {}
	bool operator < (const Point &rhs) const {
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
	Point operator - (const Point &rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
};

int F(Point p) { return p.x * p.x + p.y * p.y; } 
int CCW(Point a,Point b,Point c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

void ConvexHull(vector<Point> &pts) {
	sort(pts.begin(), pts.end());
	vector<Point> up, down;
	for (int i = 0; i < pts.size(); ++i) {
		while (up.size() >= 2 && CCW(up[up.size() - 2], up.back(), pts[i]) >= 0) up.pop_back();
		while (down.size() >= 2 && CCW(down[down.size() - 2], down.back(), pts[i]) <= 0) down.pop_back();
		up.push_back(pts[i]), down.push_back(pts[i]);
	}
	pts = up; for (int i = down.size() - 2; i > 0; --i) pts.push_back(down[i]); 
}

int n, r;
vector<Point> pts;
int res = 0;
vector<Point> opt;
vector<Point> cur;

void brute(int u,int last,int val) {
	if (u == n + 1) {
		if (val > res) {
			res = val;
			opt = cur;
		}
		return;
	}
	for (int i = last; i < pts.size(); ++i) {
		int nxt = val;
		for (auto p : cur) {
			nxt += F(p - pts[i]);
		}
		cur.push_back(pts[i]);
		brute(u + 1, i, nxt);
		cur.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> r;
	if (n % 2 == 0) {
		cout << r * r * n * n << '\n';
		for (int i = 1; i <= (n / 2); ++i) cout << 0 << ' ' << r << '\n';
		for (int i = 1; i <= (n / 2); ++i) cout << 0 << ' ' << -r << '\n';
		return 0; 
	}
	else {
		for (int i = -r; i <= r; ++i) {
			for (int j = -r; j <= r; ++j) {
				if (i * i + j * j <= r * r) {
					pts.push_back({i, j});
				}
			}
		} 
		ConvexHull(pts);
		brute(1, 0, 0);
		cout << res << '\n';
		for (auto p : opt) cout << p.x << ' ' << p.y << '\n';
	}
}