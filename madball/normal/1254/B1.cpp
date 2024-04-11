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
#include <iomanip>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef long long lint;
typedef unsigned long long ulint;
typedef long double ld;

#define For(i, n) for (int i = 0; i < (n); ++i)
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define TIMED_FUNC TimerRegion timer_func(__FUNCTION__);

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

const int MAXN = (int)1e6 + 10;
lint ar[MAXN];

lint check(int n, lint dv)
{
	vector<lint> cur;
	lint res = 0;
	For(i, n)
	{
		if (ar[i])
			cur.push_back(i);
		if (sz(cur) == dv)
		{
			lint mid = cur[dv / 2];
			for (auto e : cur)
				res += abs(e - mid);
			cur.clear();
		}
	}
	return res;
}

void solve()
{
	TIMED_FUNC;
	int n;
	scanf("%d", &n);
	For(i, n)
	{
		scanf("%lld", &ar[i]);
	}
	lint cur_n = 0;
	For(i, n)
		cur_n += ar[i];
	lint ans = -1;
	for (lint j = 2; j * j <= cur_n; ++j)
		if (cur_n % j == 0)
		{
			cur_n /= j;
			while (cur_n % j == 0)
				cur_n /= j;
			lint cur_res = check(n, j);
			if (ans == -1 || cur_res < ans)
				ans = cur_res;
		}
	if (cur_n > 1)
	{
		lint cur_res = check(n, cur_n);
		if (ans == -1 || cur_res < ans)
			ans = cur_res;
	}
	printf("%lld\n", ans);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
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