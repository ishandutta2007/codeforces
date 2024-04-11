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
#include <complex>
using namespace std;

typedef long long li;
typedef long double ld;

#define For(i, n) for (int i = 0; i < n; ++i)
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define TIMED_FUNC TimerRegion timer_func(__FUNCTION__);

struct Timer
{
	static map<string, Timer> ar;

	li time;
	li last;
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

#ifdef LOCAL
map<string, Timer> Timer::ar;
#endif

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
li inpv[MAXN];
li inpt[MAXN];
li psumt[MAXN];
li addres[MAXN];
li res[MAXN];

void solve()
{
	int n;
	scanf("%d", &n);
	For(i, n)
		scanf("%lld", &inpv[i]);
	For(i, n)
		scanf("%lld", &inpt[i]);
	psumt[0] = inpt[0];
	for (int i = 1; i < n; ++i)
		psumt[i] = psumt[i - 1] + inpt[i];
	For(i, n)
	{
		int l = i - 1;
		int r = n + 1;
		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			if (psumt[m] - (i ? psumt[i - 1] : 0) >= inpv[i])
				r = m;
			else
				l = m;
		}
		addres[i] += 1;
		if (r != n + 1)
		{
			addres[r] -= 1;
			res[r] += inpv[i] - (r ? psumt[r - 1] - (i ? psumt[i - 1] : 0) : 0);
		}
	}
	for (int i = 1; i < n; ++i)
		addres[i] += addres[i - 1];
	For(i, n)
		res[i] += addres[i] * inpt[i];
	For(i, n)
		printf("%lld ", res[i]);
}

int main()
{
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