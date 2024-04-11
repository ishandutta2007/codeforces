#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long double ldb;

typedef long long LL;

struct Equation {
	LL x1, x2;
	LL y1, y2;
	LL c;
};

Equation operator * (Equation a, LL x) {
	a.x1 *= x;
	a.x2 *= x;
	a.y1 *= x;
	a.y2 *= x;
	a.c *= x;
	return a;
};

Equation operator + (Equation a, Equation b) {
	a.x1 += b.x1;
	a.x2 += b.x2;
	a.y1 += b.y1;
	a.y2 += b.y2;
	a.c += b.c;
	return a;
};

Equation e1, e2;

LL sq(LL x) {
	return x * x;
}

ldb sq(ldb x) {
	return x * x;
}

struct Circle {
	LL x, y, r;
};

struct Point {
	ldb x, y;
};

Circle t[3];

struct DbEquation {
	ldb x1, x2;
	ldb y1, y2;
	ldb c;
	DbEquation() {}
	DbEquation(Equation e) {
		x1 = e.x1;
		x2 = e.x2;
		y1 = e.y1;
		y2 = e.y2;
		c = e.c;
	}
};

DbEquation subX(DbEquation e, ldb a, ldb c) {
	e.y1 += e.x1 * a + e.x2 * 2 * a * c;
	e.y2 += e.x2 * sq(a);
	e.c += e.x1 * c + e.x2 * sq(c);
	return e;
}

DbEquation subY(DbEquation e, ldb a, ldb c) {
	e.x1 += e.y1 * a + e.y2 * 2 * a * c;
	e.x2 += e.y2 * sq(a);
	e.c += e.y1 * c + e.y2 * sq(c);
	return e;
}

DbEquation d;

pair<ldb, ldb> solveQE(ldb a, ldb b, ldb c) {
	if(fabsl(a) < 1E-12) {
		if(fabsl(b) < 1E-12) {
			exit(0);
		}
		return make_pair(-c / b, -c / b);
	}
	ldb del = sq(b) - 4 * a * c;
	if(del < 0) exit(0);
	del = sqrtl(del);
	return make_pair((-b - del) / (2 * a), (-b + del) / (2 * a));
}

Point p[2];

ldb dist(Point p, Circle c) {
	return sqrtl(sq(p.x - c.x) + sq(p.y - c.y));
}

int main() {
	for(int i = 0; i < 3; ++i) scanf("%lld %lld %lld", &t[i].x, &t[i].y, &t[i].r);
	e1.x2 = e1.y2 = (sq(t[0].r) - sq(t[1].r));
	e1.x1 = (-2 * t[1].x * sq(t[0].r) + 2 * t[0].x * sq(t[1].r));
	e1.y1 = (-2 * t[1].y * sq(t[0].r) + 2 * t[0].y * sq(t[1].r));
	e1.c = (sq(t[0].r) * (sq(t[1].x) + sq(t[1].y)) - sq(t[1].r) * (sq(t[0].x) + sq(t[0].y)));
	e2.x2 = e2.y2 = (sq(t[0].r) - sq(t[2].r));
	e2.x1 = (-2 * t[2].x * sq(t[0].r) + 2 * t[0].x * sq(t[2].r));
	e2.y1 = (-2 * t[2].y * sq(t[0].r) + 2 * t[0].y * sq(t[2].r));
	e2.c = (sq(t[0].r) * (sq(t[2].x) + sq(t[2].y)) - sq(t[2].r) * (sq(t[0].x) + sq(t[0].y)));
	if(e1.x2 == 0) swap(e1, e2);
	Equation e = e1 * e2.x2 + e2 * -e1.x2;
	if(e.x1 == 0 && e.y1 == 0){
		if(e.c) return 0;
		e = e2;
	}
	if(e.x1 == 0) {
		d = subY(e1, -e.x1 / ldb(e.y1), -e.c / ldb(e.y1));
		pair<ldb, ldb> c = solveQE(d.x2, d.x1, d.c);
		p[0].x = c.first;
		p[0].y = -e.x1 / ldb(e.y1) * p[0].x - e.c / ldb(e.y1);
		p[1].x = c.second;
		p[1].y = -e.x1 / ldb(e.y1) * p[1].x - e.c / ldb(e.y1);
	} else {
		d = subX(e1, -e.y1 / ldb(e.x1), -e.c / ldb(e.x1));
		pair<ldb, ldb> c = solveQE(d.y2, d.y1, d.c);
		p[0].y = c.first;
		p[0].x = -e.y1 / ldb(e.x1) * p[0].y - e.c / ldb(e.x1);
		p[1].y = c.second;
		p[1].x = -e.y1 / ldb(e.x1) * p[1].y - e.c / ldb(e.x1);
	}
	if(dist(p[0], t[0]) < dist(p[1], t[0])) {
		printf("%.7Lf %.7Lf\n", p[0].x, p[0].y);
	} else {
		printf("%.7Lf %.7Lf\n", p[1].x, p[1].y);
	}
}