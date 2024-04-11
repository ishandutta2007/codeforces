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

struct Trie
{
	Trie *rf[26];
	Trie *par;
	int cnt;
	Trie() : cnt(0), par(NULL)
	{
		For(i, 26)
			rf[i] = NULL;
	}
	bool term()
	{
		For(i, 26)
			if (rf[i] != NULL)
				return false;
		return true;
	}
} trie;

void solve()
{
	TIMED_FUNC;
	Trie *cur = &trie;
	int res = 0;
	int skipping = 0;
	while (true)
	{
		char c = -1;
		c = getchar();
		if (c < 0)
			break;
		if ('a' <= c && c <= 'z')
		{
			++res;
			++cur->cnt;
			if (cur->rf[c - 'a'] == NULL)
			{
				cur->rf[c - 'a'] = new Trie();
				cur->rf[c - 'a']->par = cur;
			}
			cur = cur->rf[c - 'a'];
			if (cur->cnt == 1)
				++skipping;
			else
				skipping = 0;
			if (cur->term() && skipping > 1)
			{
				res -= skipping;
				skipping = 0;
				res += 2;
			}
		}
		else
		{
			++res;
			++cur->cnt;
			bool match = cur->term() && cur->cnt > 1;
			while (cur->par)
			{
				if (match)
					--cur->cnt;
				cur = cur->par;
			}
			if (match)
				--cur->cnt;
			skipping = 0;
		}
	}
	printf("%d", res);
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