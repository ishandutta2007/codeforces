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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")

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

const int MAXN = 150'005;
const int MOD = 998244353;
const int BIG = 100;
int big_par[MAXN];

int add(int a, int b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int sub(int a, int b)
{
	return add(a, MOD - b);
}

int mul(int a, int b)
{
	return ((lint)a * b) % MOD;
}

int pw(int a, int b)
{
	return b == 0 ? 1 : b % 2 ? mul(pw(a, b - 1), a) : pw(mul(a, a), b / 2);
}

int inv(int a)
{
	return pw(a, MOD - 2);
}

inline int f(int x)
{
	return x & (-x);
}

struct Fenvick
{
	int ar[MAXN];
	Fenvick() {}
	void add(int i, int val)
	{
		for (; i < MAXN; i += f(i + 1))
		{
			ar[i] += val;
			if (ar[i] >= MOD)
				ar[i] -= MOD;
		}
	}
	int get(int i)
	{
		int res = 0;
		for (; i != -1; i -= f(i + 1))
		{
			res += ar[i];
			if (res >= MOD)
				res -= MOD;
		}
		return res;
	}
} tree1, tree2;

vector<int> graph[MAXN];
int tin1[MAXN];
int tout1[MAXN];
int tin2[MAXN];
int sz[MAXN];
int par[MAXN];
int par2[MAXN];
int t1 = 0;
int t2 = 0;

int dfs(int v, int from)
{
	if (from != -1 && sz(graph[from]) >= BIG)
	{
		par[v] = from;
		par2[v] = v;
	}
	else if (from != -1)
	{
		par[v] = par[from];
		par2[v] = par2[from];
	}
	else
		par[v] = par2[v] = -1;
	sz[v] = 1;
	tin1[v] = t1++;
	for (auto e : graph[v])
		if (e != from)
		{
			sz[v] += dfs(e, v);
		}
	tout1[v] = t1 - 1;
	tin2[v] = t2++;
	return sz[v];
}

int vval[MAXN];
int big_val[MAXN];

void add_to_vertex(int v, int val)
{
	tree1.add(tin1[v], val);
	tree2.add(tin2[v], MOD - val);
	vval[v] = add(vval[v], val);
}

int get_vertex(int v)
{
	int res = add(add(tree1.get(tout1[v]), tree2.get(tin2[v])), vval[v]);
	while (par[v] != -1)
	{
		res = add(res, mul(sz[par2[v]], big_val[par[v]]));
		v = par[v];
	}
	return res;
}

void solve()
{
	TIMED_FUNC;
	int n, q;
	scanf("%d %d", &n, &q);
	For(i, n - 1)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(0, -1);
	int ni = inv(n);
	For(_, q)
	{
		int t, v;
		scanf("%d %d", &t, &v);
		--v;
		if (t == 1)
		{
			int d;
			scanf("%d", &d);
			if (sz(graph[v]) < BIG)
			{
				for (auto e : graph[v])
					if (sz[e] < sz[v])
					{
						add_to_vertex(e, MOD - mul(d, sz[e]));
					}
			}
			else
				big_val[v] = sub(big_val[v], d);
			add_to_vertex(v, mul(d, n - sz[v]));
			add_to_vertex(0, mul(d, sz[v]));
		}
		else
		{
			printf("%d\n", mul(get_vertex(v), ni));
		}
	}
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