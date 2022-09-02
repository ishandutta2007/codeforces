#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

typedef pair<double, double> point;

const int maxn = 100;

bool flag = 0;

double ans = -1;

int n;
point a[maxn + 5];

priority_queue<pair<double, point> > all;

void work(const int &aa, const int &bb, const int &cc)
{
	const point &p0 = a[aa], &p1 = a[bb], &p2 = a[cc];
	double a1 = p1.x - p0.x, b1 = p1.y - p0.y, c1 = (a1 * a1 + b1 * b1) / 2; 
	double a2 = p2.x - p0.x, b2 = p2.y - p0.y, c2 = (a2 * a2 + b2 * b2) / 2;
	double c3 = ((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y)) / 2;
	if (c2 + c3 < c1 + 1e-8) return;
	if (c1 + c3 < c2 + 1e-8) return;
	if (c1 + c2 < c3 + 1e-8) return;
	double d = a1 * b2 - a2 * b1;
	double x = c1 * b2 - c2 * b1, y = a1 * c2 - a2 * c1;
	all.push(mp((x * x + y * y) / (d * d), mp(x / d + p0.x, y / d + p0.y)));
}

void work0(const int &aa, const int &bb, const int &cc, const int &dd)
{
	const point &p0 = a[aa], &p1 = a[bb], &p2 = a[cc], &p3 = a[dd];
	double a1 = p1.x - p0.x, b1 = p1.y - p0.y, c1 = (a1 * a1 + b1 * b1) / 2; 
	double a2 = p2.x - p0.x, b2 = p2.y - p0.y, c2 = (a2 * a2 + b2 * b2) / 2;
	double c3 = ((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y)) / 2;
	if (min(abs(c2 + c3 - c1), min(abs(c1 + c2 - c3), abs(c1 + c3 - c2))) > 1e-8) return;
	double d = a1 * b2 - a2 * b1;
	if (abs(d) < 1e-8) return;
	double x = (c1 * b2 - c2 * b1) / d, y = (a1 * c2 - a2 * c1) / d;
	double tmp = x * x + y * y;
	x += p0.x - p3.x, y += p0.y - p3.y;
	if (abs(x * x + y * y - tmp) > 1e-8) return;
	all.push(mp(tmp, mp(x + p3.x, y + p3.y)));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%lf%lf", &a[i].x, &a[i].y);
	REP(i, 0, n)
		REP(j, 0, i)
			REP(k, 0, j)
				work(i, j, k);
	REP(i, 0, n)
		REP(j, 0, i)
			REP(k, 0, j)
				REP(l, 0, k)
					work0(i, j, k, l);
	while (!all.empty())
	{
		double x = all.top().x;
		point y = all.top().y;
		all.pop();
		REP(i, 0, n)
			if ((a[i].x - y.x) * (a[i].x - y.x) + (a[i].y - y.y) * (a[i].y - y.y) < x - 1e-8) goto lyc;
		flag = 1;
		ans = sqrt(x);
		break;
lyc:;
	}
	if (flag) printf("%lf\n", ans);
	else printf("-1\n");
	return 0;
}