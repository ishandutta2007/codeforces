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

const double INF = 1e100;
const double eps = 1e-9;
bool eq(double x, double y)
{
	return fabs(x - y) < eps;
}
double mySqrt(double x)
{
	if (x < 0) return 0;
	return sqrt(x);
}

struct Point
{
	double x, y;
	Point() : x(), y() {}
	Point(double _x, double _y) : x(_x), y(_y) {}

	Point operator + (const Point &A) const
	{
		return Point(x + A.x, y + A.y);
	}
	Point operator - (const Point &A) const
	{
		return Point(x - A.x, y - A.y);
	}
	double operator % (const Point &A) const
	{
		return x * A.x + y * A.y;
	}
	double length()
	{
		return mySqrt(*this % *this);
	}
	double distTo(const Point &A) const
	{
		return (*this - A).length();
	}

	void scan()
	{
		scanf("%lf%lf", &x, &y);
	}
};

const int N = (int) 1e5 + 100;
Point P[N];

vector <int> imp;
pair <double, int> p[N];


void addImp(int n, Point A, Point T)
{
	for (int i = 0; i < n; i++)
	{
		p[i] = make_pair(P[i].distTo(T) - A.distTo(P[i] ), i);
	}
	sort(p, p + n);
	reverse(p, p + n);
	for (int i = 0; i < min(2, n); i++)
		imp.push_back(p[i].second);
	sort(imp.begin(), imp.end() );
	imp.resize(unique(imp.begin(), imp.end() ) - imp.begin() );
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Point A, B, T;
	A.scan();
	B.scan();
	T.scan();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		P[i].scan();
	double ans = 0;
	for (int i = 0; i < n; i++)
		ans += 2 * P[i].distTo(T);
	
	addImp(n, A, T);
	addImp(n, B, T);

	double sub = -INF;
//	for (int x : imp)
//		eprintf("%d ", x);
//	eprintf("\n");
	for (int a = -1; a < (int) imp.size(); a++)
		for (int b = -1; b < (int) imp.size(); b++)
		{
			if (a == -1 && b == -1) continue;
			if (a == b && a != -1) continue;
			double cur = 0;
			if (a != -1)
				cur += P[imp[a] ].distTo(T) - A.distTo(P[imp[a] ] );
			if (b != -1)
				cur += P[imp[b] ].distTo(T) - B.distTo(P[imp[b] ] );
			sub = max(sub, cur);
		}
//	eprintf("%.10lf\n", ans);
	ans -= sub;
	printf("%.10lf\n", ans);

	return 0;
}