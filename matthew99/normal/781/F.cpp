#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
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

const int maxn = 200100;

const double eps = 1e-8;

const double inf = 1e100;

struct point
{
	double x, y;

	point() { }
	point(const double &_x, const double &_y): x(_x), y(_y) { }

	friend point operator+(const point &x, const point &y) { return point(x.x + y.x, x.y + y.y); }
	friend point operator-(const point &x, const point &y) { return point(x.x - y.x, x.y - y.y); }
	friend point operator*(const point &x, const double &y) { return point(x.x * y, x.y * y); }
	friend point operator/(const point &x, const double &y) { return point(x.x / y, x.y / y); }
	friend double operator*(const point &x, const point &y) { return x.x * y.x + x.y * y.y; }
	friend double operator^(const point &x, const point &y) { return x.x * y.y - x.y * y.x; }

};

double dist(const point &x, const point &y) { return sqrt((x - y) * (x - y)); }

int n, m;

double perimeter, period;

point a[maxn + 5];
double len[maxn + 5];

point unit[maxn + 5];

vector<pair<double, double> > ban;
pair<int, double> fir_p;

inline void add_ban(const double &l, const double &r)
{
	int num = int(l / period);
	ban.pb(mp(l - num * period, r - num * period));
	ban.pb(mp(l - num * period - period, r - num * period - period));
}

inline bool intersect(const point &u, const point &v, const double &r, pair<double, double> &ret)
{
	//(u + vt) ^ 2 < r ^ 2
	//u ^ 2 + 2uvt + v ^ 2t < r ^ 2
	//v ^ 2t + 2uvt + u ^ 2 - r ^ 2 < 0
	double c2 = v * v, c1 = u * v * 2, c0 = u * u - r * r;
	if (c2 < eps)
	{
		if (c0 < 0) 
		{
			ret = mp(-inf, inf);
			return 1;
		}
		else return 0;
	}
	double delta = c1 * c1 - c0 * c2 * 4;
	if (delta < 0) return 0;
	delta = sqrt(delta);
	ret = mp((-c1 - delta) / (2 * c2), (-c1 + delta) / (2 * c2));
	return 1;
}

inline void get_res(const double &dis)
{
	pair<int, double> ptr0, ptr1;
	ptr0 = mp(0, 0.);
	ptr1 = fir_p;
	double elapsed = 0;
	while (ptr0.x < n)
	{
		double step = min(len[ptr0.x] - ptr0.y, len[ptr1.x] - ptr1.y);

		point p0 = a[ptr0.x] + unit[ptr0.x] * ptr0.y;
		point p1 = a[ptr1.x] + unit[ptr1.x] * ptr1.y;
		pair<double, double> range;
		bool any = 0;
		if (intersect(p1 - p0, unit[ptr1.x] - unit[ptr0.x], dis, range))
		{
			chkmax(range.x, 0.);
			chkmin(range.y, step);
			if (range.y > range.x)
			{
				any = 1;
				range.x += elapsed;
				range.y += elapsed;
				add_ban(elapsed, range.x);
				add_ban(range.y, elapsed + step);
			}
		}
		if (!any) add_ban(elapsed, elapsed + step);

		elapsed += step;
		ptr0.y += step;
		if (ptr0.y > len[ptr0.x] - eps) ptr0.y -= len[ptr0.x], ++ptr0.x;
		ptr1.y += step;
		if (ptr1.y > len[ptr1.x] - eps) ptr1.y -= len[ptr1.x], ++ptr1.x;
	}
}

inline bool work(const double &dis)
{
	ban.clear();
	get_res(dis);
	sort(ALL(ban));
	double lst_end = 0;
	for (auto u : ban)
	{
		if (u.x > lst_end + eps) return 1;
		chkmax(lst_end, u.y);
	}
	if (period > lst_end + eps) return 1;
	return 0;
}

inline void get_fir_p()
{
	fir_p = mp(0, 0.);
	double res = period;
	while (1)
	{
		if (res < len[fir_p.x]) { fir_p.y = res; break; }
		res -= len[fir_p.x];
		++fir_p.x;
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%lf%lf", &a[i].x, &a[i].y), a[n + i] = a[i];
	perimeter = 0; 
	REP(i, 0, (n << 1) - 1) 
	{
		len[i] = dist(a[i], a[i + 1]);
		unit[i] = (a[i + 1] - a[i]) / len[i];
	}
	REP(i, 0, n) perimeter += len[i];
	period = perimeter / m;
	get_fir_p();
	double low = 0, high = period;
	REP(i, 0, 50)
	{
		double mid = (low + high) / 2;
		if (work(mid)) high = mid;
		else low = mid;
	}
	printf("%.15f\n", low);
	return 0;
}