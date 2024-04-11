#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long double ldb;

const ldb EPS = 1E-12;

struct point {
	ldb x, y;
	point(ldb _x = 0, ldb _y = 0) {
		x = _x;
		y = _y;
	}
};

point operator + (point a, point b) {
	return point(a.x + b.x, a.y + b.y);
}

point operator - (point a, point b) {
	return point(a.x - b.x, a.y - b.y);
}

point operator * (point a, ldb c) {
	return point(a.x * c, a.y * c);
}

point operator * (ldb c, point a) {
	return point(a.x * c, a.y * c);
}

point cinema, house, shop;

ldb dist(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ldb t1, t2;

ldb mRes(point p) {
	ldb l = 0, r = 1;
	ldb dp = dist(cinema, p);
	ldb d1 = dp + dist(p, shop);
	ldb d2 = dp + dist(p, house);
	if (d1 + EPS <= t1 && d2 + EPS <= t2) {
		return dp + min(t1 - d1, t2 - d2);
	}
	while (r - l > EPS) {
		ldb c = (l + r) / 2.0;
		point m = p + (cinema - p) * c;
		ldb dm = dist(cinema, m);
		ldb d1 = dm + dist(m, shop);
		ldb d2 = dm + dist(m, house);
		if (d1 > t1 + EPS || d2 > t2 + EPS) l = c;
		else r = c;
	}
	return dist(cinema, p + (cinema - p) * l);
}

int main() {
	scanf("%Lf %Lf", &t1, &t2);
	scanf("%Lf %Lf", &cinema.x, &cinema.y);
	scanf("%Lf %Lf", &house.x, &house.y);
	scanf("%Lf %Lf", &shop.x, &shop.y);
	t1 += dist(cinema, shop);
	t2 += dist(cinema, house);
	if (t2 >= dist(cinema, shop) + dist(shop, house)) {
		printf("%.8Lf\n", min(t1 + dist(shop, house), t2));
		return 0;
	}
	ldb l = 0, r = 1;
	while (r - l > EPS) {
		ldb c1 = l + (r - l) / 3.0;
		ldb c2 = l + 2 * (r - l) / 3.0;
		ldb r1 = mRes(house + c1 * (shop - house));
		ldb r2 = mRes(house + c2 * (shop - house));
		if (r1 > r2) r = c2;
		else l = c1;
	}
	ldb cr = mRes(house + l * (shop - house));
	l = 0, r = 1;
	while (r - l > EPS) {
		ldb c1 = l + (r - l) / 3.0;
		ldb c2 = l + 2 * (r - l) / 3.0;
		ldb r1 = mRes(house + c1 * (cinema - house));
		ldb r2 = mRes(house + c2 * (cinema - house));
		if (r1 > r2) r = c2;
		else l = c1;
	}
	cr = max(cr, mRes(house + l * (cinema - house)));
	l = 0, r = 1;
	while (r - l > EPS) {
		ldb c1 = l + (r - l) / 3.0;
		ldb c2 = l + 2 * (r - l) / 3.0;
		ldb r1 = mRes(shop + c1 * (cinema - shop));
		ldb r2 = mRes(shop + c2 * (cinema - shop));
		if (r1 > r2) r = c2;
		else l = c1;
	}
	cr = max(cr, mRes(shop + l * (cinema - shop)));
	printf("%.8Lf\n", cr);
}