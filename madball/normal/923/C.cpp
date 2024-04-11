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
#include <complex>
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

const int MAXFOREST = (int)1e7;
const int MAXN = (int)3e5 + 10;

struct Trie
{
	static Trie forest[MAXFOREST];
	static int forest_size;
	Trie *rf[2];
	int term;
	Trie()
	{
		rf[0] = rf[1] = NULL;
		term = 0;
	}
	void add(int x, int coef = 1 << 29)
	{
		++term;
		if (coef)
		{
			Trie *&nxt = rf[(bool)(x & coef)];
			if (nxt == NULL)
				nxt = &forest[forest_size++];
			nxt->add(x & ~coef, coef >> 1);
		}
	}
	int remove_closest(int x, int coef = 1 << 29)
	{
		--term;
		if (!coef)
			return 0;
		bool rf_bool_x_and_coef_is_null = rf[(bool)(x & coef)] == NULL;
		Trie *&nxt = rf_bool_x_and_coef_is_null ? rf[!(bool)(x & coef)] : rf[(bool)(x & coef)];
		int res = rf_bool_x_and_coef_is_null ? coef : 0;
		res += nxt->remove_closest(x, coef >> 1);
		if (nxt->term == 0)
			nxt = NULL;
		return res;
	}
};

Trie Trie::forest[MAXFOREST];
int Trie::forest_size = 1;
Trie root = Trie::forest[0];

int inp1[MAXN];
int inp2[MAXN];

void solve()
{
	int n;
	scanf("%d", &n);
	For(i, n)
		scanf("%d", &inp1[i]);
	For(i, n)
	{
		scanf("%d", &inp2[i]);
		root.add(inp2[i]);
	}
	For(i, n)
		printf("%d ", root.remove_closest(inp1[i]));
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