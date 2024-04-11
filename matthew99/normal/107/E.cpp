#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <set>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second

using namespace std;

const double eps = 1e-6;

inline int dcmp(const double &x) { return x < -eps ? -1 : x > eps; }

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

	friend bool operator<(const point &x, const point &y)
	{
		if (dcmp(x.x - y.x)) return x.x < y.x;
		return dcmp(x.y - y.y) < 0;
	}

	double angle() const { return atan2(y, x); }

};

bool on_seg(const point &P, const point &u, const point &v)
{
	return !dcmp((P - u) ^ (P - v)) && dcmp((P - u) * (P - v)) <= 0;
}

bool intersect(const point &P, const point &v, const point &Q, const point &w, point &O)
{
	register double t = v ^ w;
	if (!dcmp(v ^ w)) return 0;
	point u = P - Q;
	t = (w ^ u) / t;
	O = P + v * t;
	return 1;
}

int in_rect(const point &u0, const point &v0, point *rect)
{
	int cnt = 0;
	point P = (u0 + v0) / 2;
	REP(i, 0, 4)
	{
		point u = rect[i], v = rect[(i + 1) & 3];
		if (on_seg(P, u, v)) 
		{
			if (dcmp((v - u) * (v0 - u0)) < 0) return 0;
			return 1;
		}
		if (u.x > v.x) swap(u, v);
		if (dcmp((v - u) ^ (P - u)) > 0)
		{
			cnt += dcmp(u.x - P.x) < 0 && dcmp(v.x - P.x) >= 0;
		}
	}
	return cnt & 1 ? 2 : 0;
}

const int maxn = 600;

int n;
point rect[maxn + 5][4];
bool f[maxn + 5][maxn + 5];

double ans = 0, ret = 0;

void init()
{
	srand(time(NULL));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		double sum = 0;
		REP(j, 0, 4) scanf("%lf%lf", &rect[i][j].x, &rect[i][j].y);
		REP(j, 0, 4) sum += rect[i][j] ^ rect[i][(j + 1) & 3];
		if (!dcmp(sum)) --n, --i;
		if (sum < 0) reverse(rect[i], rect[i] + 4), sum = -sum;
		ans += sum;
	}
}

point O;
double ang[maxn * 100 + 5];
int pos[maxn * 100 + 5];
int ty[maxn * 100 + 5];
int has[maxn + 5];

inline bool cmp(const int &x, const int &y)
{
	return dcmp(ang[x] - ang[y]) < 0;
}

inline bool cmp0(const int &x, const int &y)
{
	return !dcmp(ang[x] - ang[y]);
}

void solve()
{
	REP(i, 0, n)
	{
		O = point(0.0, 0.0);
		double Minx = 1e100;
		REP(a, 0, 4) O = O + rect[i][a];
		O = O / 4;
		double lyc = O.y - eps;
		REP(a, 0, 4) 
		{
			if (dcmp(lyc - rect[i][a].y) * dcmp(lyc - rect[i][(a + 1) & 3].y) <= 0)
				Minx = min(Minx, ((lyc - rect[i][a].y) * rect[i][(a + 1) & 3].x + (rect[i][(a + 1) & 3].y - lyc) * rect[i][a].x) / (rect[i][(a + 1) & 3].y - rect[i][a].y));
		}
		static point p[maxn * 100 + 5];
		int pn = 0;
		int posn = 0;
		REP(a, 0, 4) ty[pn] = 0, pos[posn++] = pn, p[pn] = rect[i][a], ang[pn] = (p[pn] - O).angle(), ++pn;
		REP(j, 0, n)
		{
			if (j == i) continue;
			int lst = pn;
			int lst0 = posn;
			p[pn++] = point(Minx, O.y - eps);
			REP(a, 0, 4)
			{
				point &u0 = rect[i][a], &v0 = rect[i][(a + 1) & 3];
				p[pn++] = rect[i][a];
				REP(b, 0, 4)
				{
					point &u1 = rect[j][b], &v1 = rect[j][(b + 1) & 3];
					if (intersect(u0, v0 - u0, u1, v1 - u1, p[pn]) && on_seg(p[pn], u0, v0) && on_seg(p[pn], u1, v1)) ++pn;
				}
			}
			REP(k, lst, pn) ang[k] = (p[k] - O).angle(), pos[posn++] = k; 
			sort(pos + lst0, pos + posn, cmp);
			posn = unique(pos + lst0, pos + posn, cmp0) - pos;
			REP(k, lst0, posn) 
			{
				int tmp = in_rect(p[pos[k]], p[pos[k + 1 >= posn ? lst0 : k + 1]], rect[j]);
				if (tmp == 1)
				{
					if (i > j) tmp = 0;
				}
				ty[pos[k]] = tmp ? j + 1 : -j - 1;
			}
		}
		sort(pos, pos + posn, cmp);
		int cnt = 0;
		memset(has, 0, sizeof has);
		REP(j, 0, posn)
		{
			int &x = pos[j];
			if (ty[x] < 0)
			{
				if (has[-ty[x] - 1]) --cnt, has[-ty[x] - 1] = 0;
			}
			else if (ty[x] > 0)
			{
				if (!has[ty[x] - 1]) ++cnt, has[ty[x] - 1] = 1;
			}
			if (!cnt) 
			{
				point u = p[pos[j]], v = p[pos[(j + 1) % posn]];
				ret += u ^ v;
			}
		}
	}
	ans = ans / ret;
}

void output() { printf("%.15lf\n", ans); }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("needle.in", "r", stdin);
	freopen("needle.out", "w", stdout);
#endif
	init();
	solve();
	output();
	return 0;
}