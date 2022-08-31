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
	long long x, y;
	Point() : x(), y() {}
	Point(long long _x, long long _y) : x(_x), y(_y) {}
	Point operator + (const Point &A) const { return Point(x + A.x, y + A.y); }
	Point operator - (const Point &A) const { return Point(x - A.x, y - A.y); }
	long long operator * (const Point &A) const { return x * A.y - y * A.x; }
	long long operator % (const Point &A) const { return x * A.x + y * A.y; }
	double length() { return sqrt(double(*this % *this) ); }
	double distTo(Point A) { return (*this - A).length(); }
	void read() { scanf("%lld%lld", &x, &y); }
	bool operator <= (const Point &A) const
	{
		if (x != A.x)
			return x < A.x;
		return y <= A.y;
	}
	bool operator < (const Point &A) const
	{
		return *this * A > 0;
	}
	bool operator == (const Point &A) const
	{
		return x == A.x && y == A.y;
	}
	Point negate()
	{
		return Point(-x, -y);
	}
	bool isIn(vector <Point> v)
	{
		for (int i = 1; i < (int) v.size(); i++)
		{
			if ( (v[i - 1] - *this) * (v[i] - *this) <= 0)
				return false;
		}
		return true;
	}
	bool operator != (Point A)
	{
		return !(*this == A);
	}
};

const int MAGIC = 100;
const int maxn = (int) 1e5 + 100;
double pow2[maxn];
Point P[maxn];
double rp[maxn];

double getProb(int len, int n)
{
	int diff = n - len;
	double ans = 1. / pow2[diff];
	if (n < MAGIC)
	{
		double up = pow2[n];
		up -= 1. + n + (double) n * (double) (n - 1) / 2.;
		double down = pow2[len];
		down -= 1.;
		ans = down / up;
	}
//	eprintf("len = %d, n = %d, p = %.10lf\n", len, n, ans);
	return ans;
}

void init()
{
	pow2[0] = 1;
	for (int i = 1; i < MAGIC; i++)
		pow2[i] = pow2[i - 1] * 2.;
}

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void solve()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n - 1; i++)
	{
		rp[i] = getProb(i, n);
	}
	for (int i = 0; i < n; i++)
	{
		P[i].read();
	}
	double ES = 0, EB = 0;
	for (int i = 0; i < n; i++)
		for (int skip = 0; skip + 2 < n && skip < MAGIC - 5; skip++)
		{
			int len = n - skip - 2;
			double p = rp[len];
			Point A = P[i];
			Point B = P[ (i + skip + 1) % n];
			double s = (double) (A * B) / 2.;
			ES += s * p;
			int dx = abs(A.x - B.x);
			int dy = abs(A.y - B.y);
			int g = gcd(dx, dy);

			EB += g * p;

//			eprintf("i = %d, skip = %d, s = %.5lf, g = %d\n", i, skip, s, g);
		}
//	eprintf("ES = %.10lf, EB = %.10lf\n", ES, EB);
	double ans = ES + 1 - EB / 2.;
	printf("%.10lf\n", ans);
}


int main(int , char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	init();
	solve();

	return 0;
}