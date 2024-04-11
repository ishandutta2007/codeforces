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

const int MAXN = 1000;

int dp[3][MAXN];
int ar[MAXN];

void solve()
{
	TIMED_FUNC;
	int n;
	cin >> n;
	For(i, n)
		cin >> ar[i];
	dp[0][0] = 0;
	dp[1][0] = MAXN;
	dp[2][0] = MAXN;
	For(i, n)
	{
		dp[0][i + 1] = min(dp[0][i], min(dp[1][i], dp[2][i])) + 1;
		if (ar[i] & 1)
			dp[1][i + 1] = min(dp[0][i], dp[2][i]);
		else
			dp[1][i + 1] = MAXN;
		if (ar[i] & 2)
			dp[2][i + 1] = min(dp[0][i], dp[1][i]);
		else
			dp[2][i + 1] = MAXN;
	}
	cout << min(dp[0][n], min(dp[1][n], dp[2][n]));
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