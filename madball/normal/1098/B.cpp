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

int cnt(const vector<string>& ar, int i, char a, char b, bool vertical)
{
	int res = 0;
	if (vertical)
	{
		For(j, sz(ar))
			if (ar[j][i] != (j % 2 == 0 ? a : b))
				++res;
	}
	else
	{
		For(j, sz(ar[i]))
			if (ar[i][j] != (j % 2 == 0 ? a : b))
				++res;
	}
	return res;
}

void fil(vector<string>& ans, int i, char a, char b, bool vertical)
{
	if (vertical)
	{
		For(j, sz(ans))
			ans[j][i] = (j % 2 == 0 ? a : b);
	}
	else
	{
		For(j, sz(ans[i]))
			ans[i][j] = (j % 2 == 0 ? a : b);
	}
}

void doit(const vector<string>& ar, int& res, vector<string>& ans, char a, char b, char c, char d, bool vertical)
{
	int res2 = 0;
	int n = sz(ar), m = sz(ar[0]);
	vector<string> ans2(n, string(m, 0));
	if (vertical)
	{
		For(i, m)
		{
			char cur_a = (i % 2 == 0 ? a : c), cur_b = (i % 2 == 0 ? b : d);
			int ab = cnt(ar, i, cur_a, cur_b, true), ba = cnt(ar, i, cur_b, cur_a, true);
			if (ab <= ba)
				fil(ans2, i, cur_a, cur_b, true);
			else
				fil(ans2, i, cur_b, cur_a, true);
			res2 += min(ab, ba);
		}
	}
	else
	{
		For(i, n)
		{
			char cur_a = (i % 2 == 0 ? a : c), cur_b = (i % 2 == 0 ? b : d);
			int ab = cnt(ar, i, cur_a, cur_b, false), ba = cnt(ar, i, cur_b, cur_a, false);
			if (ab <= ba)
				fil(ans2, i, cur_a, cur_b, false);
			else
				fil(ans2, i, cur_b, cur_a, false);
			res2 += min(ab, ba);
		}
	}
	if (res2 < res)
	{
		res = res2;
		ans = ans2;
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<string> ar(n);
	vector<string> ans(n, string(m, 0));
	For(i, n)
		cin >> ar[i];
	int res = n * m;
	doit(ar, res, ans, 'A', 'G', 'C', 'T', false);
	doit(ar, res, ans, 'A', 'C', 'G', 'T', false);
	doit(ar, res, ans, 'A', 'T', 'C', 'G', false);
	doit(ar, res, ans, 'C', 'T', 'A', 'G', false);
	doit(ar, res, ans, 'G', 'T', 'A', 'C', false);
	doit(ar, res, ans, 'C', 'G', 'A', 'T', false);
	doit(ar, res, ans, 'A', 'G', 'C', 'T', true);
	doit(ar, res, ans, 'A', 'C', 'G', 'T', true);
	doit(ar, res, ans, 'A', 'T', 'C', 'G', true);
	doit(ar, res, ans, 'C', 'T', 'A', 'G', true);
	doit(ar, res, ans, 'G', 'T', 'A', 'C', true);
	doit(ar, res, ans, 'C', 'G', 'A', 'T', true);
#ifdef LOCAL
	cout << res << '\n';
#endif
	for (auto e : ans)
		cout << e << '\n';
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