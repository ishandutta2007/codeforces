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

const int MAXN = 102;
char ar[MAXN][MAXN];
char ar2[MAXN][MAXN];
const string ALPH = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void solve()
{
	TIMED_FUNC;
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int rice = 0;
	For(i, n) For(j, m)
	{
		scanf(" %c", &ar[i][j]);
		if (ar[i][j] == 'R')
			++rice;
	}
#ifdef LOCAL
	memcpy(ar2, ar, sizeof(ar));
#endif
	int cur = 0;
	int taken = 0;
	For(i, n) For(j, m)
	{
		int x = i;
		int y = i % 2 ? m - 1 - j : j;
		if (ar[x][y] == 'R')
			++taken;
		ar[x][y] = ALPH[min(cur, k - 1)];
		if (taken * k >= (cur + 1) * rice)
			++cur;
	}
	For(i, n)
	{
		ar[i][m] = 0;
		printf("%s\n", ar[i]);
	}
#ifdef LOCAL
	map<char, int> mp;
	For(i, n) For(j, m)
	{
		if (ar2[i][j] == '.')
			continue;
		char c = ar[i][j];
		if (mp.count(c))
			++mp[c];
		else
			mp[c] = 1;
	}
	for (auto e : mp)
		printf("%c %d\n", e.first, e.second);
#endif
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int t;
	scanf("%d", &t);
	For(i, t)
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