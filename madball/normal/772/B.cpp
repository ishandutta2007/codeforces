#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int LIM = 1005;
const ll INF = 3e+18;
const ld EPS = 1e-7;

#ifdef LOCAL
//#define STRESS
#endif

struct Point
{
	ll x, y;
	Point() {}
	Point(ll _x, ll _y): x(_x), y(_y) {}
	Point operator + (Point const p) const
	{
		return Point(x + p.x, y + p.y);
	}
	Point operator-() const
	{
		return Point(-x, -y);
	}
	Point operator - (Point const p) const
	{
		return (*this) + (-p);
	}
	ll operator * (Point const p) const
	{
		return x * p.y - y * p.x;
	}
	ll operator % (Point const p) const
	{
		return x * p.x + y * p.y;
	}
	bool operator == (Point const p) const
	{
		return x == p.x && y == p.y;
	}
	ll len2() const
	{
		return x * x + y * y;
	}
	double len() const
	{
		return sqrt((double)len2());
	}
	double dist2(Point const p1, Point const p2) const
	{
		return abs((p1 - (*this)) * (p2 - (*this))) / (p1 - p2).len();
	}
};

double res = INF;

void doit(Point const p1, Point const p2, Point const ph)
{
	if (p1 == p2 || p1 == ph || p2 == ph)
		return;
	res = min(res, ph.dist2(p1, p2));
}

Point poly[LIM];

void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> poly[i].x >> poly[i].y;
	}
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			doit(poly[i], poly[j], poly[(i + 1) % n]);
			doit(poly[i], poly[j], poly[(i + n - 1) % n]);
			doit(poly[i], poly[j], poly[(j + 1) % n]);
			doit(poly[i], poly[j], poly[(j + n - 1) % n]);
		}
	cout.precision(20);
	cout << res / 2 << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
	return 0;
}