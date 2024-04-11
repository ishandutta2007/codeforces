#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const double eps = 1e-8;

inline int dcmp(const double &x)
{
	return x < -eps ? -1 : x > eps;
}

const int maxn = 100000;
const int LIMIT = 1.9 * CLOCKS_PER_SEC;

int n, k;

struct point
{
	double x, y;

	point() { }
	point(const double &_x, const double &_y): x(_x), y(_y) { }

};

struct line
{
	double a, b, c;

	line() { }
	line(const double &_a, const double &_b, const double &_c): a(_a), b(_b), c(_c) { }

	bool check(const point &p) const
	{
		return !dcmp(a * p.x + b * p.y + c);
	}

	friend bool operator==(const line &x, const line &y)
	{
		return !dcmp(x.a - y.a) && !dcmp(x.b - y.b) && !dcmp(x.c - y.c);
	}

};

inline bool ok(const line &x, const line &y)
{
	return dcmp(x.a * y.b - x.b * y.a);
}

inline point sec(const line &x, const line &y)
{
	double tmp = x.a * y.b - x.b * y.a;
	point ret;
	ret.x = (-x.c * y.b - x.b * -y.c) / tmp;
	ret.y = (x.a * -y.c - -x.c * y.a) / tmp;
	return ret;
}

line a[maxn + 5];

vector<pair<int, int> > now;

bool dfs(const vector<int> &lis, const int &k, const int &dep = 0)
{
	if (SZ(lis) == 0)
	{
		printf("YES\n");
		printf("%d\n", SZ(now));
		for (auto it : now) printf("%d %d\n", it.x, it.y);
		return 1;
	}
	if (!k) return 0;
	int n = SZ(lis);
	int sz = (n + k - 1) / k;
	REP(i, 0, dep == 0 ? oo : min((LL)n * (n + 1) / 2, (LL)k * k))
	{
		if (clock() > LIMIT) return 0;
		int x = rand() % n;
		int y = rand() % (x + 1);
		x = lis[x], y = lis[y];
		vector<int> nxt;
		int cnt = 0;
		if (x == y) 
		{
			now.pb(mp(x + 1, -1));

			for (auto it : lis)
			{
				if (a[it] == a[x]) ++cnt;
				else nxt.pb(it);
			}

		}
		else 
		{
			if (!ok(a[x], a[y])) continue;
			point goal = sec(a[x], a[y]);
			now.pb(mp(x + 1, y + 1));

			for (auto it : lis)
			{
				if (a[it].check(goal)) ++cnt;
				else nxt.pb(it);
			}

		}

		if (cnt >= sz && dfs(nxt, k - 1, dep + 1)) return 1;

		now.pop_back();
	}
	return 0;
}

inline void init()
{
	scanf("%d%d", &n, &k);
	REP(i, 0, n) 
	{
		scanf("%lf%lf%lf", &a[i].a, &a[i].b, &a[i].c);
		if (!dcmp(a[i].a)) a[i].c /= a[i].b, a[i].b = 1;
		else a[i].b /= a[i].a, a[i].c /= a[i].a, a[i].a = 1;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	srand(time(NULL));
#endif
	init();
	vector<int> lis;
	REP(i, 0, n) lis.pb(i);
	if (!dfs(lis, k)) printf("NO\n");
	return 0;
}