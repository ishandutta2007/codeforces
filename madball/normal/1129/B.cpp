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

lint find_answer(const vector<lint>& ar)
{
	int n = sz(ar);
	lint res = 0, cur = 0, k = -1;
	For(i, n)
	{
		cur += ar[i];
		if (cur < 0)
		{
			cur = 0;
			k = i;
		}
		res = max(res, (i - k) * cur);
	}
	return res;
}

lint doit(const vector<lint>& ar)
{
	lint res = 0;
	int n = sz(ar);
	For(i, n)
	{
		lint cur = 0;
		for (int j = i; j < n; ++j)
		{
			cur += ar[j];
			res = max(res, cur * (j - i + 1));
		}
	}
	return res;
}

void solve()
{
	lint k;
	cin >> k;
	vector<lint> res;
	for (int n = 3; res.empty() && n <= 2000; n += 2)
	{
		for (int a = 0; a <= 1000000; ++a)
		{
			int b = (a - (n - 1) / 2) * n - k;
			if (b <= 0 || a >= b)
				continue;
			if (b >= 1000000)
				break;
			res.push_back(a);
			for (int i = 1; i < n; ++i)
				res.push_back(i % 2 ? -b - 1 : b);
			break;
		}
	}
	if (res.empty())
		throw;
	cout << sz(res) << '\n';
	for (auto e : res)
		cout << e << ' ';
	cout << '\n';
#ifdef LOCAL
	cout << doit(res) - find_answer(res) << '\n';
	cout << doit(res) << ' ' << find_answer(res) << '\n';
#endif
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