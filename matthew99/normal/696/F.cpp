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
	friend point &operator*=(point &x, const double &y) { x.x *= y, x.y *= y; return x; }
	friend point operator/(const point &x, const double &y) { return point(x.x / y, x.y / y); }
	friend point &operator/=(point &x, const double &y) { x.x /= y, x.y /= y; return x; }
	friend bool operator<(const point &x, const point &y) { if (!dcmp(x.x - y.x)) return dcmp(x.y - y.y) < 0; return x.x < y.x; }
	friend double operator*(const point &x, const point &y) { return x.x * y.x + x.y * y.y; }
	friend double operator^(const point &x, const point &y) { return x.x * y.y - x.y * y.x; }
	double length() { return sqrt(x * x + y * y); }
	double length2() { return x * x + y * y; }

};

const int maxn = 300;

int n;
point a[maxn + 5];

inline double dis(const point &k, const point &i, const point &j) { return ((i - k) ^ (j - k)) / (j - i).length(); }

inline double calc(int x, int y, bool out)
{
	if ((y - x + n) % n <= 2)
	{
		if (out) printf("%.15f %.15f\n", a[(x + 1) % n].x, a[(x + 1) % n].y);
		return 0;
	}
	if (((a[(x + 1) % n] - a[x]) ^ (a[(y + n - 1) % n] - a[y])) > 0) return 1e100;
	double u = -dis(a[x], a[(y + n - 1) % n], a[y]);
	for (int i = x, nxt; i != y; i = nxt)
	{
		nxt = (i + 1) % n;
		double v = dis(a[nxt], a[x], a[(x + 1) % n]) - dis(a[nxt], a[(y + n - 1) % n], a[y]);
		if ((u > 0) != (v > 0))
		{
			point p = (a[i] * v - a[nxt] * u) / (v - u);
			if (out) printf("%.15f %.15f\n", p.x, p.y);
			return dis(p, a[x], a[(x + 1) % n]);
		}
		u = v;
	}
	assert(0);
	return 1e100;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	scanf("%d", &n);
	REP(i, 0, n) scanf("%lf%lf", &a[i].x, &a[i].y);
	double ans = 1e100;
	int ansx = -1, ansy = -1;
	REP(i, 0, n) REP(j, i + 2, n)
		if (chkmin(ans, max(calc(i, j, 0), calc(j, i, 0)))) ansx = i, ansy = j;
	printf("%.15f\n", ans);
	calc(ansx, ansy, 1);
	calc(ansy, ansx, 1);
	return 0;
}