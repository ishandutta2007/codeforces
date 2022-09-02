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

const int maxn = 400100;

const double eps = 1e-8;

inline int dcmp(const double &x) { return x < -eps ? -1 : x > eps; }

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
	friend bool operator<(const point &x, const point &y) { if (!dcmp(x.x - y.x)) return dcmp(x.y - y.y) < 0; return x.x < y.x; }
	friend double operator*(const point &x, const point &y) { return x.x * y.x + x.y * y.y; }
	friend double operator^(const point &x, const point &y) { return x.x * y.y - x.y * y.x; }

} O(0, 0);

inline bool line_line(const point &P, const point &v, const point &Q, const point &w, double &x)
{
	point u = P - Q;
	if (!dcmp(v ^ w)) return 0;
	x = (w ^ u) / (v ^ w);
	return 1;
}

struct line
{
	point p, v;

	line() { }
	line(const point &_p, const point &_v): p(_p), v(_v) { }

};

inline point get_intersection(const line &x, const line &y)
{
	double ret = 0;
	assert(line_line(x.p, x.v, y.p, y.v, ret));
	return x.p + x.v * ret;
}

inline bool on_left(const line &l, const point &p)
{
	return (l.v ^ (p - l.p)) > 0;
}

inline bool half_plane(line *plane, const int &n_plane, point *poly, int &n_poly)
{
	static int pos[maxn + 5];
	static double ang[maxn + 5];
	REP(i, 0, n_plane) ang[i] = atan2(plane[i].v.y, plane[i].v.x), pos[i] = i;

	sort(pos, pos + n_plane, [&](int x, int y) { return ang[x] < ang[y]; });

	int head, rear;
	static point p[maxn + 5];
	static line q[maxn + 5];
	head = rear = 0;
	q[rear++] = plane[pos[0]];
	REP(i, 1, n_plane)
	{
		while (head < rear - 1 && !on_left(plane[pos[i]], p[rear - 2])) --rear;
		while (head < rear - 1 && !on_left(plane[pos[i]], p[head])) ++head;
		q[rear++] = plane[pos[i]];
		if (abs(q[rear - 1].v ^ q[rear - 2].v) < eps)
		{
			--rear;
			if (on_left(q[rear - 1], plane[pos[i]].p)) q[rear - 1] = plane[pos[i]];
		}
		if (head + 1 < rear) p[rear - 2] = get_intersection(q[rear - 2], q[rear - 1]);
	}
	while (head < rear - 1 && !on_left(q[head], p[rear - 2])) --rear;
	if (abs(q[head].v ^ q[rear - 1].v) < eps)
	{
		if (on_left(q[rear - 1], q[head].p)) --rear;
		else ++head;
	}
	if (head + 1 >= rear) return 0;
	p[rear - 1] = get_intersection(q[rear - 1], q[head]);

	n_poly = 0;
	REP(i, head, rear) poly[n_poly++] = p[i];
	return 1;
}

int n;
line plane[maxn + 5];
int n_plane = 0;
point a[maxn + 5];
bool bel[maxn + 5];

int pos[maxn + 5];

inline bool cmp(int x, int y)
{
	return bel[x] == bel[y] ? (a[x] ^ a[y]) > 0 : bel[x] < bel[y];
};

inline bool find_colinear()
{
	REP(i, 0, n) if (abs(a[pos[i]] ^ a[pos[(i + 1) % n]]) < eps) return 1;
	return 0;
}

inline void add_restrict(const point &u, const point &v)
{
	if (on_left(line(u, v - u), O)) plane[n_plane++] = line(u, v - u);
	else plane[n_plane++] = line(v, u - v);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		REP(i, 0, n) scanf("%lf%lf", &a[(i + n - 1) % n].x, &a[(i + n - 1) % n].y);
		--n;
		REP(i, 0, n) a[i] -= a[n];
		REP(i, 0, n)
		{
			if (a[i].y) bel[i] = a[i].y > 0;
			else bel[i] = a[i].x > 0;
		}
		REP(i, 0, n) pos[i] = i;
		sort(pos, pos + n, cmp);
		if (find_colinear()) printf("0\n");
		else
		{
			n_plane = 0;
			int j = 0;
			REP(i, 0, n)
			{
				add_restrict(a[pos[i]], a[pos[(i + 1) % n]]);
				while (j <= i || (j < i + n && (a[pos[i]] ^ a[pos[j % n]]) > 0)) ++j;
				if (j < i + n) add_restrict(a[pos[i]], a[pos[j % n]]);
			}
			static point res[maxn + 5];
			int res_n = 0;
			plane[n_plane++] = line(point(-1e6, -1e6) - a[n], point(2e6, 0));
			plane[n_plane++] = line(point(1e6, -1e6) - a[n], point(0, 2e6));
			plane[n_plane++] = line(point(1e6, 1e6) - a[n], point(-2e6, 0));
			plane[n_plane++] = line(point(-1e6, 1e6) - a[n], point(0, -2e6));
			half_plane(plane, n_plane, res, res_n);
			double ans = 0;
			REP(i, 0, res_n) ans += res[i] ^ res[(i + 1) % res_n];
			ans /= 2;
			printf("%.15f\n", ans);
		}
	}

	return 0;
}