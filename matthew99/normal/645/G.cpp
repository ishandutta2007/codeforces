#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int Mod = 1e9 + 7;

const double pi = acos(-1.0);
const double eps = 1e-8;

inline int dcmp(double x) { return x < -eps ? -1 : x > eps; }

struct point
{
	double x, y;

	point() { }
	point(const double &_x, const double &_y): x(_x), y(_y) { }

	friend point operator+(const point &x, const point &y) { return point(x.x + y.x, x.y + y.y); }
	friend point &operator+=(point &x, const point &y) { x.x += y.x, x.y += y.y; return x; }
	friend point operator-(const point &x, const point &y) { return point(x.x - y.x, x.y - y.y); }
	friend point &operator-=(point &x, const point &y) { x.x -= y.x, x.y -= y.y; return x; }
	friend point operator*(const point &x, const double &y) { return point(x.x * y, x.y * y); }
	friend point operator/(const point &x, const double &y) { return point(x.x / y, x.y / y); }
	friend bool operator<(const point &x, const point &y) { if (!dcmp(x.x - y.x)) return dcmp(x.y - y.y) < 0; return dcmp(x.x - y.x) < 0; }
	friend double operator*(const point &x, const point &y) { return x.x * y.x + x.y * y.y; }
	friend double operator^(const point &x, const point &y) { return x.x * y.y - x.y * y.x; }

	double angle() const{ return atan2(y, x); }

};

inline bool line_line(const point &P, const point &v, const point &Q, const point &w, double &x)
{
	point u = P - Q;
	if (!dcmp(v ^ w)) return 0;
	x = (w ^ u) / (v ^ w);
	return 1;
}

inline bool line_cir(const point &u, const point &v, const point &O, const double &r, double &x, double &y)
{
	point w = u - O;
	double a = v * v, b = 2 * (v * w), c = w * w - r * r;
	double delta = b * b - 4 * (a * c);
	if (delta <= 0) return 0;
	delta = sqrt(delta);
	x = (-b - delta) / (2 * a);
	y = (-b + delta) / (2 * a);
	return 1;
}

inline bool cir_cir(const point &O0, const double &r0, const point &O1, const double &r1, double &x, double &y)
{
	point u = O1 - O0;
	double ang = u.angle();
	double tmp0 = u * u;
	double tmp1 = (tmp0 + r0 * r0 - r1 * r1) / (2 * sqrt(tmp0) * r0);
	if (tmp1 >= 1 || tmp1 <= -1) return 0;
	tmp1 = acos(tmp1);
	x = ang - tmp1;
	y = ang + tmp1;
	return 1;
}

const int maxn = 100000;

int n;
int p;
point a[maxn + 5];

double dis[maxn + 5];

inline bool check(const double &x)
{
	vector<pair<double, double> > all;
	REP(i, 0, n)
	{
		double l, r;
		if (cir_cir(point(p, 0), x, a[i], dis[i], l, r))
		{
			if (l < 0) l += 2 * pi;
			if (r < 0) r += 2 * pi;
			if (l > r) swap(l, r);
			all.pb(mp(l, r));
		}
	}
	sort(ALL(all));
	set<double> now;
	for (auto x : all)
	{
		auto t = now.lower_bound(x.x);
		if (t != now.end() && *t < x.y) return 1;
		now.insert(x.y);
	}
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &p);
	REP(i, 0, n) scanf("%lf%lf", &a[i].x, &a[i].y), dis[i] = sqrt((a[i] - point(-p, 0)) * (a[i] - point(-p, 0)));
	double l = 0, r = 2 * p;
	while (clock() <= 2.5 * CLOCKS_PER_SEC)
	{
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%.15f\n", l);
	return 0;
}