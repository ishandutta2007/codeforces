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

#ifdef LOCAL
#define STRESS
#endif

lint gcd(lint a, lint b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

lint div_cnt(lint a)
{
	lint res = 1;
	for (lint i = 2; i * i <= a; ++i)
	{
		if (a % i)
			continue;
		lint cur = 0;
		while (a % i == 0)
		{
			a /= i;
			++cur;
		}
		res *= cur + 1;
	}
	if (a > 1)
		res *= 2;
	return res;
}

void get_divs(lint a, vector<lint> &ar)
{
	ar.clear();
	for (lint i = 1; i * i <= a; ++i)
	{
		if (a % i == 0)
			ar.push_back(i);
	}
	for (lint i = 1; i * i < a; ++i)
	{
		if (a % i == 0)
			ar.push_back(a / i);
	}
	reverse(ar.begin() + (sz(ar) + 1) / 2, ar.end());
}

lint get_get(vector<lint> ar)
{
	lint res = 0;
	res += ar[0] * (ar[0] + 1) * (ar[0] + 2) / 6;
	res += ar[0] * (ar[0] + 1) / 2 * ar[2];
	res += ar[0] * (ar[0] + 1) / 2 * ar[3];
	res += ar[0] * (ar[0] + 1) / 2 * ar[6];
	res += ar[0] * (ar[0] + 1) / 2 * ar[1];
	res += ar[0] * ar[1] * ar[2];
	res += ar[0] * ar[1] * ar[3];
	res += ar[0] * ar[1] * ar[6];
	res += ar[0] * ar[3] * ar[2];
	res += ar[3] * (ar[3] + 1) / 2 * ar[0];
	res += ar[0] * ar[3] * ar[6];
	res += ar[0] * (ar[0] + 1) / 2 * ar[5];
	res += ar[0] * ar[5] * ar[2];
	res += ar[0] * ar[5] * ar[3];
	res += ar[0] * ar[5] * ar[6];
	res += ar[1] * (ar[1] + 1) / 2 * ar[0];
	res += ar[1] * (ar[1] + 1) / 2 * ar[2];
	res += ar[1] * (ar[1] + 1) / 2 * ar[3];
	res += ar[1] * (ar[1] + 1) / 2 * ar[6];
	res += ar[1] * ar[3] * ar[2];
	res += ar[3] * (ar[3] + 1) / 2 * ar[1];
	res += ar[1] * ar[3] * ar[6];
	res += ar[1] * ar[5] * ar[0];
	res += ar[1] * ar[5] * ar[2];
	res += ar[1] * ar[5] * ar[3];
	res += ar[1] * ar[5] * ar[6];
	res += ar[2] * (ar[2] + 1) / 2 * ar[0];
	res += ar[2] * ar[0] * ar[6];
	res += ar[2] * (ar[2] + 1) / 2 * ar[1];
	res += ar[2] * ar[1] * ar[6];
	res += ar[2] * (ar[2] + 1) / 2 * ar[3];
	res += ar[3] * (ar[3] + 1) / 2 * ar[2];
	res += ar[2] * ar[3] * ar[6];
	res += ar[2] * (ar[2] + 1) / 2 * ar[5];
	res += ar[2] * ar[5] * ar[3];
	res += ar[2] * ar[5] * ar[6];
	res += ar[0] * (ar[0] + 1) / 2 * ar[4];
	res += ar[4] * ar[0] * ar[2];
	res += ar[4] * ar[0] * ar[3];
	res += ar[4] * ar[0] * ar[6];
	res += ar[4] * ar[1] * ar[0];
	res += ar[4] * ar[1] * ar[2];
	res += ar[4] * ar[1] * ar[3];
	res += ar[4] * ar[1] * ar[6];
	res += ar[4] * ar[3] * ar[2];
	res += ar[3] * (ar[3] + 1) / 2 * ar[4];
	res += ar[4] * ar[3] * ar[6];
	res += ar[4] * ar[5] * ar[0];
	res += ar[4] * ar[5] * ar[2];
	res += ar[4] * ar[5] * ar[3];
	res += ar[4] * ar[5] * ar[6];
	return res;
}

void solve()
{
	TIMED_FUNC;
	vector<lint> inp(3);
	For(i, 3)
		cin >> inp[i];
	sort(all(inp));
	lint A = inp[0], B = inp[1], C = inp[2];
#ifdef STRESS
	lint sres = 0;
	for (lint a = 1; a <= C; ++a)
		for (lint b = a; b <= C; ++b)
			for (lint c = b; c <= C; ++c)
			{
				do
				{
					if (inp[0] % a == 0 && inp[1] % b == 0 && inp[2] % c == 0)
					{
						++sres;
						break;
					}
				} while (next_permutation(all(inp)));
				sort(all(inp));
			}
	cout << sres << ' ';
#endif
	vector<lint> ar(7);
	ar[0] = div_cnt(gcd(gcd(A, B), C));
	ar[1] = div_cnt(gcd(A, B)) - ar[0];
	ar[2] = div_cnt(gcd(A, C)) - ar[0];
	ar[3] = div_cnt(gcd(B, C)) - ar[0];
	ar[4] = div_cnt(A) - ar[1] - ar[2] - ar[0];
	ar[5] = div_cnt(B) - ar[1] - ar[3] - ar[0];
	ar[6] = div_cnt(C) - ar[2] - ar[3] - ar[0];
	lint res = get_get(ar);
	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
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