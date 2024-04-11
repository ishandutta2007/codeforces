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
typedef long long ll;
typedef long double ld;

#define TIMED_FUNC TimerRegion timer_func(__FUNCTION__);
#define For(i, n) for (int i = 0; i < n; ++i)
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()

struct Timer
{
	static map<string, Timer> ar;

	ll time;
	ll last;
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
const int INF = (int)1e9 + 7;
const double EPS = 1e-9;

int ar[MAXN];

void solve()
{
	TIMED_FUNC;
	int n, u;
	scanf("%d %d", &n, &u);
	For(i, n)
		scanf("%d", &ar[i]);
	int j = 0;
	double res = -1;
	for (int i = 0; i < n; ++i)
	{
		while (j + 1 < n && ar[j + 1] - ar[i] <= u)
			++j;
		if (i + 1 < j)
		{
			res = max(res, ((double)(ar[j] - ar[i + 1])) / (ar[j] - ar[i]));
		}
	}
	if (res < -0.5)
		printf("-1");
	else
		printf("%.10lf", res);
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