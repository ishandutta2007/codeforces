#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int LIM = 20100;
const int INF = 1e+9 + 7;
const ld EPS = 1e-7;

#ifdef LOCAL
//#define STRESS
#endif

char s[9];
int get_time()
{
	return s[7] + 10 * (s[6] + 6 * (s[4] + 10 * (s[3] + 6 * (s[1] + 10 * (s[0])))));
}

int color[LIM];

struct Event
{
	int t;
	bool close;
	int id;
	Event() {}
	Event(int _t, bool _close, int _id): t(_t), close(_close), id(_id) {}
	int &get_color() const
	{
		return color[id];
	}
	bool operator < (Event const &e) const
	{
		if (t != e.t)
			return t < e.t;
		return close < e.close;
	}
};

Event events[LIM * 2];
int open_cnt[LIM];

void solve()
{
	int n, m, t;
	scanf("%d %d %d", &n, &m, &t);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", &s);
		for (int k = 0; k < 8; ++k)
			s[k] -= '0';
		int cur_time = get_time();
		events[i * 2] = Event(cur_time, false, i);
		events[i * 2 + 1] = Event(cur_time + t - 1, true, i);
	}
	sort(events, events + n * 2);
	int resm = 0;
	int opencnt = 0;
	int openr = 0;
	for (int i = 0; i < n * 2; ++i)
	{
		if (events[i].close)
		{
			--open_cnt[events[i].get_color()];
			if (open_cnt[events[i].get_color()] == 0)
				--opencnt;
		}
		else
		{
			if (opencnt < m)
			{
				++openr;
				++opencnt;
				resm = max(resm, opencnt);
			}
			events[i].get_color() = openr;
			++open_cnt[events[i].get_color()];
		}
	}
	if (resm < m)
		printf("No solution\n");
	else
	{
		printf("%d\n", openr);
		for (int i = 0; i < n; ++i)
			printf("%d\n", color[i]);
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
	return 0;
}