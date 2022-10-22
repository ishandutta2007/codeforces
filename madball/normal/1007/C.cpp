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

#ifdef LOCAL
//#define INTERACTOR
#endif

lint ask(lint x, lint y)
{
	cout << x + 1 << ' ' << y + 1 << endl;
	lint ans;
	cin >> ans;
	return ans;
}

pair<lint, lint> what(lint W, lint w, lint H, lint h)
{
	double A = H * 1.0 / W;
	double B = -3.0 * H;
	double C = (double)(H * w + h * W - h * w);
	double D = B * B - 4 * A * C;
	double xd = (-B - sqrt(D)) / (2 * A);
	xd = (1.5 - sqrt(2.25 - 1.0 * (w * 1.0 / W + h * 1.0 / H - (h * 1.0 / H) * (w * 1.0 / W)))) * W;
	double yd = H * xd / W;
	return { lint(xd), lint(yd) };
}

void solve()
{
	lint n;
	cin >> n;
	bool corner = false;
	lint lft = 0;
	lint rgt = n;
	lint bot = 0;
	lint top = n;
	lint wid = 0;
	lint hei = 0;
	while (true)
	{
#ifdef LOCAL
		if (corner)
			cout << "State: corner from (" << lft << ", " << bot << ") to (" << rgt << ", " << top << "), width = " << wid << ", height = " << hei << endl;
		else
			cout << "State: rectangle from (" << lft << ", " << bot << ") to (" << rgt << ", " << top << ")" << endl;
#endif
		if (corner)
		{
			lint x, y;
			tie(x, y) = what(rgt - lft, wid, top - bot, hei);
			x += lft;
			y += bot;
			lint ans = ask(x, y);
			if (ans == 0)
				return;
			if (ans == 1)
			{
				wid -= x + 1 - lft;
				lft = x + 1;
			}
			if (ans == 2)
			{
				hei -= y + 1 - bot;
				bot = y + 1;
			}
			if (ans == 3)
			{
				wid = x - lft;
				hei = y - bot;
			}
			if (wid <= 0)
			{
				corner = false;
				top = bot + hei;
			}
			else if (hei <= 0)
			{
				corner = false;
				rgt = lft + wid;
			}
		}
		else
		{
			lint x = (lft + rgt) / 2;
			lint y = (bot + top) / 2;
			lint ans = ask(x, y);
			if (ans == 0)
				return;
			if (ans == 1)
				lft = x + 1;
			if (ans == 2)
				bot = y + 1;
			if (ans == 3)
			{
				corner = true;
				wid = x - lft;
				hei = y - bot;
			}
			if (corner)
			{
				if (wid <= 0)
				{
					corner = false;
					top = bot + hei;
				}
				else if (hei <= 0)
				{
					corner = false;
					rgt = lft + wid;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
#ifdef INTERACTOR
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