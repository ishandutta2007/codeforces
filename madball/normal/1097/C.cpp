#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

#ifdef LOCAL
#pragma comment(linker, "/STACK:16777216")
#endif

struct Seq
{
	int delta, req;
	Seq(const string& s)
	{
		delta = req = 0;
		for (auto c:  s)
		{
			delta += c == '(' ? 1 : -1;
			req = max(req, -delta);
		}
	}
	bool can_concat(const Seq& other) const
	{
		return delta + other.delta == 0 && req == 0 && delta >= other.req;
	}
	bool operator < (const Seq& other) const
	{
		return req < other.req;
	}
};

void solve()
{
	int n;
	cin >> n;
	vector<vector<Seq>> up(500001);
	vector<vector<Seq>> down(500001);
	bool wut = false;
	For(i, n)
	{
		string s;
		cin >> s;
		Seq se(s);
		if (se.delta == 0)
		{
			if (se.req == 0)
			{
				(wut ? up : down)[0].push_back(se);
				wut = !wut;
			}
		}
		else if (se.delta > 0)
			up[se.delta].push_back(se);
		else
			down[-se.delta].push_back(se);
	}
	int res = 0;
	For(i, sz(up))
	{
		sort(all(up[i]));
		sort(all(down[i]));
		For(j, min(sz(up[i]), sz(down[i])))
			if (up[i][j].can_concat(down[i][j]))
				++res;
	}
	cout << res;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}