#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


struct Point
{
	double x, y;
	Point() : x(), y() {}
	Point(double _x, double _y) : x(_x), y(_y) {}
	double operator * (Point A) { return x * A.y - y * A.x; }
	Point operator + (Point A) { return Point(x + A.x, y + A.y); }
	Point operator - (Point A) { return Point(x - A.x, y - A.y); }
	Point operator * (double a) { return Point(x * a, y * a); }
	Point rotate() { return Point(-y, x); }
	Point rotate(double alpha)
	{
		return *this * cos(alpha) + rotate() * sin(alpha);
	}
	void eprint()
	{
		eprintf("%.5lf %.5lf\n", x, y);
	}
};

double ang = atan2(-1., 0.) * 2. / 3.;

double a[10];
Point P[10];

void solve()
{
	for (int i = 0; i < 6; i++)
		scanf("%lf", &a[i] );

	Point v = Point(1, 0);
	Point X = Point(0, 0);
	for (int i = 0; i < 6; i++)
	{
		P[i] = X;
		X = X + v * a[i];
		v = v.rotate(-ang);
	}

	double one = sqrt(3.) / 4.;

	double s = 0;
	for (int i = 0; i + 1 < 6; i++)
	{
		s += fabs((P[i] - P[0] ) * (P[i + 1] - P[i] )) / 2.;
	}
	double ans = s / one;
	eprintf("s = %.5lf, one = %.5lf : %.5lf\n", s, one, ans);
	int answer = (int) (ans + 0.5);
	printf("%d\n", answer);
}


int main(int , char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	solve();

	return 0;
}