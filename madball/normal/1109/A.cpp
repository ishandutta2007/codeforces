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

lint count(const vector<int>& ar)
{
	lint res = 0;
	int l = 0;
	while (l < sz(ar))
	{
		int r = l;
		for (; r < sz(ar) && ar[r] == ar[l]; ++r);
		res += (lint)(r - l) * (r - l - 1) / 2;
		l = r;
	}
	return res;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> ar(n);
	For(i, n)
		cin >> ar[i];
	int pref = 0;
	vector<int> even(1, 0), odd;
	For(i, n)
	{
		pref = pref ^ ar[i];
		(i % 2 ? even : odd).push_back(pref);
	}
	sort(all(even));
	sort(all(odd));
	lint res = count(even) + count(odd);
	cout << res << '\n';
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