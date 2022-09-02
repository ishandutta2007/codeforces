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

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int Mod = 1e9 + 7;
const int oo = 0x3f3f3f3f;

const long double pi = acos(-1.0);
const long double eps = 1e-8;

inline int dcmp(long double x) { return x < -eps ? -1 : x > eps; }

struct point
{
	long double x, y;

	point() { }
	point(const long double &_x, const long double &_y): x(_x), y(_y) { }

	friend point operator+(const point &x, const point &y) { return point(x.x + y.x, x.y + y.y); }
	friend point &operator+=(point &x, const point &y) { x.x += y.x, x.y += y.y; return x; }
	friend point operator-(const point &x, const point &y) { return point(x.x - y.x, x.y - y.y); }
	friend point &operator-=(point &x, const point &y) { x.x -= y.x, x.y -= y.y; return x; }
	friend point operator*(const point &x, const long double &y) { return point(x.x * y, x.y * y); }
	friend point operator/(const point &x, const long double &y) { return point(x.x / y, x.y / y); }
	friend bool operator<(const point &x, const point &y) { if (!dcmp(x.x - y.x)) return dcmp(x.y - y.y) < 0; return x.x < y.x; }
	friend long double operator*(const point &x, const point &y) { return x.x * y.x + x.y * y.y; }
	friend long double operator^(const point &x, const point &y) { return x.x * y.y - x.y * y.x; }

	long double angle() const{ return atan2(y, x); }

};

bool line_line(const point &P, const point &v, const point &Q, const point &w, long double &x)
{
	point u = P - Q;
	if (!dcmp(v ^ w)) return 0;
	x = (w ^ u) / (v ^ w);
	return 1;
}

bool line_cir(const point &u, const point &v, const point &O, const long double &r, long double &x, long double &y)
{
	point w = u - O;
	long double a = v * v, b = 2 * (v * w), c = w * w - r * r;
	long double delta = b * b - 4 * (a * c);
	if (delta <= 0) return 0;
	delta = sqrt(delta);
	x = (-b - delta) / (2 * a);
	y = (-b + delta) / (2 * a);
	return 1;
}

const int maxn = 50000;
int n;

point O;

point s[maxn + 5], t[maxn + 5];

vector<pair<pair<long double, long double>, int> > all;
vector<long double> X;
int c[maxn + 5];

inline LL calc(long double mid)
{
	all.clear();
	REP(j, 0, n)
	{
		long double x, y;
		if (line_cir(s[j], t[j], O, mid, x, y)) 
		{
			all.pb(mp(mp((s[j] + t[j] * x - O).angle(), (s[j] + t[j] * y - O).angle()), j));
		}
	}
	for (auto &it : all) if (it.x.x > it.x.y) swap(it.x.x, it.x.y);
	X.clear();
	for (auto it : all) X.pb(it.x.y);
	sort(ALL(X));
	sort(ALL(all));
	memset(c, 0, sizeof c);
	LL cnt = 0;
	for (auto it : all)
	{
		int tmp = lower_bound(ALL(X), it.x.y) - X.begin() + 1, tmp0 = lower_bound(ALL(X), it.x.x) - X.begin() + 1;
		for (int i = tmp - 1; i > 0; i -= i & -i) cnt += c[i];
		for (int i = tmp0 - 1; i > 0; i -= i & -i) cnt -= c[i];
		for (int i = tmp; i <= n; i += i & -i) ++c[i];
	}
	return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	scanf("%d", &n);
	int x, y;
	scanf("%d%d%d", &x, &y, &m);
	O = point(x / 1000.0, y / 1000.0);
	REP(i, 0, n)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		s[i] = point(0, b / 1000.0);
		t[i] = point(1, (a + b) / 1000.0);
		t[i] = t[i] - s[i];
	}
	long double l = 0, r = 1e20; 
	REP(i, 0, 120)
	{
		long double mid = (l + r) / 2;
		if (calc(mid) >= m) r = mid;
		else l = mid;
	}
	double ans = 0;
	if (calc(l) > m) printf("0\n"); 
	else
	{
		ans += (m - calc(l)) * l;
		set<pair<int, int> > lyc;
		for (auto it : all)
		{
			int tmp = lower_bound(ALL(X), it.x.y) - X.begin() + 1, tmp0 = lower_bound(ALL(X), it.x.x) - X.begin() + 1;
			while (!lyc.empty() && lyc.begin()->x < tmp0) lyc.erase(lyc.begin());
			if (!lyc.empty())
			{
				for (auto it0 : lyc)
				{
					if (it0.x >= tmp) break;
					long double zzj;
					assert(line_line(s[it.y], t[it.y], s[it0.y], t[it0.y], zzj));
					point p = s[it.y] + t[it.y] * zzj;
					ans += sqrt(max((long double)0, (p - O) * (p - O)));
				}
			}
			lyc.insert(mp(tmp, it.y));
		}
	}
	printf("%.15f\n", (double)ans);
	return 0;
}