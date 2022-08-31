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

	Point operator - (const Point &A) const
	{
		return Point(x - A.x, y - A.y);
	}
	double operator * (const Point &A) const
	{
		return x * A.y - y * A.x;
	}
	double operator % (const Point &A) const
	{
		return x * A.x + y * A.y;
	}
	double length() const
	{
		return sqrt(x * x + y * y);
	}
	double distTo(const Point &A) const
	{
		return (*this - A).length();
	}
	double distTo(const Point &A, const Point &B)
	{
		if ((B - A) % (*this - A) < 0 || (A - B) % (*this - B) < 0)
			return min(distTo(A), distTo(B) );
		return fabs( (*this - A) * (*this - B)) / A.distTo(B);
	}

	void read()
	{
		scanf("%lf%lf", &x, &y);
	}
};

const int N = (int) 1e5 + 100;
Point P[N];

const double pi = atan2(0., -1.);

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	Point C;
	int n;
	scanf("%d", &n);
	C.read();
	for (int i = 0; i < n; i++)
		P[i].read();

	double mn = P[0].distTo(C), mx = P[0].distTo(C);

	for (int i = 0; i < n; i++)
	{
		double x = P[i].distTo(C);
		mn = min(mn, x);
		mx = max(mx, x);
	
		double d = C.distTo(P[i], P[ (i + 1) % n] );
		mn = min(mn, d);
	}

	double ans = pi * (mx * mx - mn * mn);

	printf("%.10lf\n", ans);

	return 0;
}