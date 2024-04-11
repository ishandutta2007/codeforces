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

void solve()
{
	TIMED_FUNC;
	int n, k, a, b, c, d;
	cin >> n >> k >> a >> b >> c >> d;
	if (n == 4 || k <= n)
	{
		cout << -1;
		return;
	}
	--a;
	--b;
	--c;
	--d;

	set<int> freee;
	For(i, n)
		freee.insert(i);
	freee.erase(a);
	freee.erase(b);
	freee.erase(c);
	freee.erase(d);
	vector<int> ar;
	for (auto e : freee)
		ar.push_back(e);

	vector<int> ans1, ans2;
	ans1.push_back(a);
	ans1.push_back(c);
	for (auto e : ar)
		ans1.push_back(e);
	ans1.push_back(d);
	ans1.push_back(b);

	ans2.push_back(c);
	ans2.push_back(a);
	for (auto e : ar)
		ans2.push_back(e);
	ans2.push_back(b);
	ans2.push_back(d);

	for (auto e : ans1)
		cout << e + 1 << ' ';
	cout << '\n';
	for (auto e : ans2)
		cout << e + 1 << ' ';
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