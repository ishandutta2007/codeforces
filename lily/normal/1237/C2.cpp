
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

struct Point {
	int x, y, z, id;
	bool operator < (const Point &a) const {
		if (x != a.x) return x < a.x;
		if (y != a.y) return y < a.y;
		return z < a.z;
	}
};


LL dist(Point a, Point b) {
	LL x = a.x - b.x, y = a.y - b.y, z = a.z - b.z;
	return x *x + y *y +z * z;
}

vector <Point> p;

int n;

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		read(x); read(y); read(z);
		Point a = {x, y, z, i};
		p.push_back(a);
	}
	sort(p.begin(), p.end());
	vector <Point> s;
	for (int i = 0; i < n; i++) {
		if (s.size() && s.back().x == p[i].x && s.back().y == p[i].y) {
			printf("%d %d\n", s.back().id, p[i].id);
			s.pop_back();
		}
		else {
			s.push_back(p[i]);
		}
	}
	p = s;
	s.clear();
	for (int i = 0; i < (int)p.size(); i++) {
		if (s.size() && s.back().x == p[i].x) {
			printf("%d %d\n", s.back().id, p[i].id);
			s.pop_back();
		}
		else {
			s.push_back(p[i]);
		}
	}
	while (s.size()) {
		int i = s.back().id;
		s.pop_back();
		int j = s.back().id;
		s.pop_back();
		printf("%d %d\n", i, j);
	}
}