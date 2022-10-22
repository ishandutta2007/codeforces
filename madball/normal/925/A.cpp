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
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef long long lint;
typedef unsigned long long ulint;
typedef long double ld;

#define For(i, n) for (int i = 0; i < n; ++i)
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
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

const int MAXN = (int)1e5 + 10;

bool inside(int x, int l, int r)
{
	return l <= x && x < r;
}

void solve()
{
	TIMED_FUNC;
	int n, m, cl, ce, v;
	cin >> n >> m >> cl >> ce >> v;
	static int ladders[MAXN];
	static int elevators[MAXN];
	For(i, cl)
		cin >> ladders[i];
	For(i, ce)
		cin >> elevators[i];
	sort(ladders, ladders + cl);
	sort(elevators, elevators + ce);
	int q;
	cin >> q;

	static int ladder_indices[2];
	static int elevator_indices[2];
	For(i, q)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		ladder_indices[0] = upper_bound(ladders, ladders + cl, c1) - ladders;
		ladder_indices[1] = ladder_indices[0] - 1;
		elevator_indices[0] = upper_bound(elevators, elevators + ce, c1) - elevators;
		elevator_indices[1] = elevator_indices[0] - 1;
		int res = (int)1e9;
		For(j, 2)
			if (inside(ladder_indices[j], 0, cl))
			{
				int c = ladders[ladder_indices[j]];
				res = min(res, abs(c1 - c) + abs(r1 - r2) + abs(c - c2));
			}
		For(j, 2)
			if (inside(elevator_indices[j], 0, ce))
			{
				int c = elevators[elevator_indices[j]];
				res = min(res, abs(c1 - c) + (abs(r1 - r2) + v - 1) / v + abs(c - c2));
			}
		if (r1 == r2)
			res = min(res, abs(c1 - c2));
		cout << res << '\n';
	}
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