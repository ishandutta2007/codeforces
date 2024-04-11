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

const int MAXN = (int)1e5 + 10;
vector<int> graph[MAXN];
int degree[MAXN];

struct Tally
{
	map<int, int> cnt;
	set<pair<int, int>> inv;
	int size;
	Tally() : size(0) {}
	void reserve(int val)
	{
		cnt[val] = 0;
		inv.emplace(0, val);
	}
	void add(int val)
	{
		++size;
		auto it = cnt.find(val);
		if (it == cnt.end() || it->first != val)
		{
			cnt[val] = 1;
			inv.emplace(1, val);
		}
		else
		{
			pair<int, int> cur(it->second, it->first);
			inv.erase(cur);
			++it->second;
			++cur.first;
			inv.insert(cur);
		}
	}
	void remove(int val)
	{
		--size;
		auto it = cnt.find(val);
		pair<int, int> cur(it->second, it->first);
		inv.erase(cur);
		--it->second;
		--cur.first;
		inv.insert(cur);
	}
	pair<int, int> best()
	{
		return *inv.begin();
	}
};

void solve()
{
	TIMED_FUNC;
	int n, m;
	scanf("%d %d", &n, &m);
	For(i, m)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	For(i, n)
		sort(all(graph[i]));
	vector<int> q;
	q.push_back(0);
	Tally tally;
	tally.reserve(0);
	for (auto e : graph[0])
		tally.add(0);
	set<int> untaken;
	for (int i = 1; i < n; ++i)
		untaken.insert(i);
	int res = 0;
	For(cur_n, n - 1)
	{
		auto p = tally.best();
		int to_add = -1;
		if (p.first == n - cur_n - 1)
		{
			to_add = *untaken.begin();
			++res;
		}
		else
		{
			for (auto e : untaken)
				if (!binary_search(all(graph[p.second]), e))
				{
					to_add = e;
					break;
				}
			if (to_add == -1)
				throw;
		}
		untaken.erase(to_add);
		tally.reserve(to_add);
		for (auto e : graph[to_add])
			if (untaken.count(e))
				tally.add(to_add);
			else
				tally.remove(e);
	}
	printf("%d\n", res);
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