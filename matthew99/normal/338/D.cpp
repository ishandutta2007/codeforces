#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define foreach(e, x) for (__typeof__((x).begin()) e = (x).begin(); e != (x).end(); ++e)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

const int maxk = 10000;

LL n, m;
int k;

LL a[maxk + 5];

void init()
{
	scanf("%I64d%I64d%d", &n, &m, &k);
	REP(i, 0, k) scanf("%I64d", a + i);
}

map<LL, pair<LL, LL> > lyc;

LL gcd(LL x, LL y) { while (y) y ^= x ^= y ^= x %= y; return x; }

LL ex_gcd(LL a, LL b, LL &x, LL &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	LL d = ex_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

LL fp(LL b, LL e)
{
	LL t = 1;
	for ( ; e; e >>= 1, b *= b) if (e & 1) t *= b;
	return t;
}

void solve()
{
	LL orz = 1;
	LL lst;
	REP(i, 0, k)
	{
		lst = orz;
		long double t = (((long double)orz * a[i]) / gcd(orz, a[i]) + 0.5);
		if (t > 1e13) EXIT("NO\n");
		orz = (LL)t;
		LL pmxm = orz / lst;
		if (pmxm > 1)
		{
			for (int j = 2; (LL)j * j <= pmxm; ++j)
			{
				int cnt = 0;
				while (!(pmxm % j)) ++cnt, pmxm /= j;
				if (cnt) lyc[j].y += cnt, lyc[j].x = -i;
			}
			if (pmxm > 1) ++lyc[pmxm].y, lyc[pmxm].x = -i;
		}
	}
	if (orz > n) EXIT("NO\n");
	LL ydc = 0;
	foreach(e, lyc)
	{
		LL yyt = fp(e->x, e->y.y);
		LL pmxm = orz / yyt;
		LL x, y;
		ex_gcd(yyt, pmxm, x, y);
		long double t = (((long double)y * pmxm) / orz);
		LL a = y * pmxm - LL(t) * orz;
		a %= orz;
		(ydc += a * e->y.x) %= orz;
	}
	if (ydc < 0) ydc += orz;
	if (!ydc) ydc += orz;
	if (ydc + k - 1 > m) EXIT("NO\n");
	for (LL i = ydc; i != ydc + k; ++i)
		if (gcd(i, orz) != a[i - ydc]) EXIT("NO\n");
}

void output()
{
	printf("YES\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	solve();
	output();
	return 0;
}