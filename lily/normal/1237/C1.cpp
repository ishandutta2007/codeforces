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
	for (int i = 1; i <= n / 2; i++) {
		LL dis = 0x3f3f3f3f3f3f3f3f; int id = 0;
		for (int j = 1; j < p.size(); j++) {
			LL x = dist(p[0], p[j]);
			if (x < dis) {
				id = j;
				dis = x;
			}
		}
		printf("%d %d\n", p[0].id, p[id].id);
		swap(p[id], p[p.size() - 1]);
		p.pop_back();
		swap(p[0], p[p.size() - 1]);
		p.pop_back();
	}
}