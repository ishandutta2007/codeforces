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

const long double eps = 1e-12;

const int maxn = 200000, max0 = 1000000;

int n, t, q;

int p[maxn + 5], l[maxn + 5], put[maxn + 5];

long double inv[max0 + 5];

inline long double val(int i)
{
	return p[i] * ((put[i] + 1) * inv[l[i] + put[i] + 1] - put[i] * inv[l[i] + put[i]]);
}

inline long double val0(int i)
{
	return p[i] * ((put[i] - 1) * inv[l[i] + put[i] - 1] - put[i] * inv[l[i] + put[i]]);
}

struct cmp
{
	bool operator()(int x, int y) const
	{ 
		long double tmp0 = val(x), tmp1 = val(y);
		if (abs(tmp0 - tmp1) < eps) return x < y;
		return tmp0 > tmp1; 
	}
};

struct cmp0
{
	bool operator()(int x, int y) const
	{ 
		long double tmp0 = val0(x), tmp1 = val0(y);
		if (abs(tmp0 - tmp1) < eps) return x < y;
		return tmp0 > tmp1; 
	}
};

multiset<int, cmp> all;
multiset<int, cmp0> all0;

long double ans = 0;

inline void erase(int x)
{
	ans -= put[x] * inv[l[x] + put[x]] * p[x];
	if (put[x] < l[x]) all.erase(all.find(x));
	if (put[x]) all0.erase(all0.find(x));
}

inline void add(int x)
{
	ans += put[x] * inv[l[x] + put[x]] * p[x];
	if (put[x] < l[x]) all.insert(x);
	if (put[x]) all0.insert(x);
}

inline bool change()
{
	if (all.empty() || all0.empty()) return 0;
	auto t0 = *all.begin(), t1 = *all0.begin();
	long double tmp = val(t0) + val0(t1);
	if (t0 == t1 || tmp <= eps) return 0;
	erase(t0), erase(t1);
	++put[t0], --put[t1];
	add(t0), add(t1);
	return 1;
}

inline bool add()
{
	if (!t) return 0;
	if (all.empty()) return 0;
	--t;
	auto t = *all.begin();
	erase(t);
	++put[t];
	add(t);
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	REP(i, 1, max0) inv[i] = 1.0 / i;
	scanf("%d%d%d", &n, &t, &q);
	REP(i, 0, n) scanf("%d", p + i);
	REP(i, 0, n) scanf("%d", l + i);
	REP(i, 0, n) add(i);
	while (add());
	REP(i, 0, q)
	{
		int ty, x;
		scanf("%d%d", &ty, &x), --x;
		erase(x);
		if (ty == 1) ++l[x];
		else
		{
			--l[x];
			while (put[x] > l[x]) --put[x], ++t;
		}
		add(x);
		while (change());
		while (add());
		printf("%.15f\n", (double)ans);
	}
	return 0;
}