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

const int MAXN = (int)2e5 + 10;
int n;
int ar[MAXN];
int res[MAXN];
int tim[MAXN];
int curt = 0;

int dfs(int v)
{
	tim[v] = curt;
	if (tim[ar[v]] == curt)
		return v;
	if (tim[ar[v]])
		return -1;
	return dfs(ar[v]);
}

void solve()
{
	TIMED_FUNC;
	scanf("%d", &n);
	For(i, n)
	{
		scanf("%d", &ar[i]);
		--ar[i];
	}
	set<int> wut;
	For(i, n)
		if (!tim[i])
		{
			++curt;
			int a = dfs(i);
			if (a != -1)
				wut.insert(a);
		}
	int me = -1;
	for (auto e : wut)
		if (ar[e] == e)
			me = e;
	if (me == -1)
		me = *wut.begin();
	For(i, n)
		res[i] = wut.count(i) ? me : ar[i];
	int ans = 0;
	For(i, n)
		if (ar[i] != res[i])
			++ans;
	printf("%d\n", ans);
	For(i, n)
		printf("%d ", res[i] + 1);
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