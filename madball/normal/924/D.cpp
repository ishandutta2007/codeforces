#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <ctime>
#include <cstring>
#include <random>
using namespace std;

typedef long long li;
typedef long long lint;
typedef long double ld;

#define TIMED_FUNC TimerRegion timer_func(__FUNCTION__);
#define For(i, n) for (int i = 0; i < n; ++i)
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()

struct Timer
{
	static map<string, Timer> ar;

	lint time;
	lint last;
	bool running;
	int count;
	Timer() : time(0), running(false), count(0) {}
#ifdef LOCAL
	void start()
	{
		if (running)
			throw;
		running = true;
		last = clock();
	}
	void stop()
	{
		if (!running)
			throw;
		running = false;
		time += clock() - last;
		++count;
	}
	static void start(string name)
	{
		if (!ar.count(name))
			ar[name] = Timer();
		ar[name].start();
	}
	static void stop(string name)
	{
		if (!ar.count(name))
			throw;
		ar[name].stop();
	}
	ld time_f()
	{
		return (ld)time / CLOCKS_PER_SEC;
	}
	ld avg_time_f()
	{
		return time_f() / count;
	}
#else
	void start() {}
	void stop() {}
	static void start(string name) {}
	static void stop(string name) {}
	ld time_f() { return 0; }
	ld avg_time_f() { return 0; }
#endif
};

map<string, Timer> Timer::ar;

struct TimerRegion
{
	string name;
	TimerRegion(string _name) : name(_name)
	{
		Timer::start(name);
	}
	~TimerRegion()
	{
		Timer::stop(name);
	}
};

const int MAXN = (int)1e5 + 100;

int f(int x)
{
	return x & (-x);
}

struct Fenvick
{
	int ar[MAXN];
	Fenvick() {};
	void add(int i)
	{
		for (; i >= 0; i -= f(i + 1))
			++ar[i];
	}
	int get(int i)
	{
		int res = 0;
		for (; i < MAXN; i += f(i + 1))
			res += ar[i];
		return res;
	}
} fenvick;

lint invs(int *ar, int n)
{
	lint res = 0;
	For(i, n)
	{
		res += fenvick.get(ar[i]);
		fenvick.add(ar[i]);
	}
	return res;
}

struct Point
{
	int id;
	lint x, y;
	Point() : id(0), x(0), y(0) {}
	Point(lint _x, lint _y) : id(0), x(_x), y(_y) {}
	Point(int _id, lint _x, lint _y) : id(_id), x(_x), y(_y) {}
	Point operator - (Point const &p) const
	{
		return Point(x - p.x, y - p.y);
	}
	lint operator * (Point const &p) const
	{
		return x * p.y - y * p.x;
	}
	lint len2() const
	{
		return x * x + y * y;
	}
};

lint w;

bool comp1(Point const &a, Point const &b)
{
	lint p = (a.x > 0 ? a - Point(0, w) : Point(0, w) - a) * (b.x > 0 ? b - Point(0, w) : Point(0, w) - b);
	if (p)
		return p > 0;
	if ((a.x < 0) != (b.x < 0))
		return b.x < 0;
	if (a.x < 0)
	{
		if ((a - Point(0, w)).len2() != (b - Point(0, w)).len2())
			return (a - Point(0, w)).len2() > (b - Point(0, w)).len2();
	}
	else
	{
		if ((a - Point(0, w)).len2() != (b - Point(0, w)).len2())
			return (a - Point(0, w)).len2() < (b - Point(0, w)).len2();
	}
	throw;
}

bool comp2(Point const &a, Point const &b)
{
	lint p = (a.x > 0 ? a - Point(0, -w) : Point(0, -w) - a) * (b.x > 0 ? b - Point(0, -w) : Point(0, -w) - b);
	if (p)
		return p > 0;
	if ((a.x < 0) != (b.x < 0))
		return b.x > 0;
	if (a.x < 0)
	{
		if ((a - Point(0, -w)).len2() != (b - Point(0, -w)).len2())
			return (a - Point(0, -w)).len2() < (b - Point(0, -w)).len2();
	}
	else
	{
		if ((a - Point(0, -w)).len2() != (b - Point(0, -w)).len2())
			return (a - Point(0, -w)).len2() > (b - Point(0, -w)).len2();
	}
	throw;
}

Point inp[MAXN];
int ind[MAXN], ind2[MAXN];

#ifdef LOCAL
#define STRESS
#endif

int sign(lint x)
{
	return x > 0 ? 1 : x == 0 ? 0 : -1;
}

void solve()
{
	TIMED_FUNC;
	int n;
	int l = 0, r = 0;
	scanf("%d %lld", &n, &w);
	For(i, n)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		inp[i] = Point(i, a, b);
	}
	sort(inp, inp + n, comp1);
	For(i, n)
		ind2[inp[i].id] = i;
	sort(inp, inp + n, comp2);
	For(i, n)
		ind[i] = ind2[inp[i].id];
	lint ans = invs(ind, n);
	printf("%lld", ans);
#ifdef STRESS
	lint sans = 0;
	For(i, n) For(j, n)
	{
		if (inp[i].x >= inp[j].x)
			continue;
		lint num = inp[i] * inp[j];
		lint den = inp[j].x - inp[i].x;
		if (-w * den <= num && num <= w * den)
			++sans;
	}
	printf(" %lld", sans);
/*	if (ans != sans)
	{
		fflush(stdout);
		throw;
	}*/
#endif
}

int main()
{
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	printf("\n\n");
	for (auto it : Timer::ar)
	{
		printf("%s = %.3lf\n", it.first.c_str(), it.second.time_f());
	}
#endif
	return 0;
}