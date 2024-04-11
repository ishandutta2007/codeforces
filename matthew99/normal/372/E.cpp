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

const int maxn = 1000;

const long double eps = 1e-15;

int n;

long double x[maxn + 5], y[maxn + 5];

inline bool eq(const long double &x, const long double &y)
{
	return abs(x - y) < eps || abs(x - y) < eps * abs(x);
}

struct data
{
	long double a, b, k;

	data() { }
	data(const long double &_a, const long double &_b, const long double &_k): a(_a), b(_b), k(_k) { }

	friend bool operator<(const data &x, const data &y)
	{
		return eq(x.a, y.a) ? eq(x.b, y.b) ? x.k < y.k : x.b < y.b : x.a < y.a;
	}

};

vector<data> all;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		double tmp = 1.0 / (a * a * d * d + c * c * b * b);
		x[i] = tmp * a * b * d * d;
		y[i] = tmp * c * b * b * d;
	}
	REP(i, 0, n) REP(j, 0, i) all.pb(data(x[i] + x[j], y[i] + y[j], eq(x[i] - x[j], 0) ? 1e100 : (y[i] - y[j]) / (x[i] - x[j])));
	sort(ALL(all));
	int m = SZ(all);
	int ans = 0;
	for (int i = 0; i < m; )
	{
		int j = i;
		while (j < m && eq(all[i].a, all[j].a) && eq(all[i].b, all[j].b)) ++j;
		int tmp = 1;
		for (int k = i; k < j; )
		{
			int l = k;
			while (l < j && eq(all[k].k, all[l].k)) ++l;
			tmp = (LL)tmp * (l - k + 1) % Mod;
			k = l;
		}
		(ans += tmp) %= Mod;
		(ans -= j - i + 1) %= Mod;
		i = j;
	}
	printf("%d\n", ans);
	return 0;
}