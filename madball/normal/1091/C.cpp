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

void solve()
{
	lint n;
	cin >> n;
	vector<lint> divs;
	for (lint i = 1; i * i <= n; ++i)
		if (n % i == 0)
		{
			divs.push_back(i);
			divs.push_back(n / i);
		}
	vector<lint> res;
	for (auto e : divs)
	{
		res.push_back((2 + (n / e) * (e - 1)) * e / 2);
	}
	sort(all(res));
	res.resize(unique(all(res)) - res.begin());
	for (auto e : res)
		cout << e << ' ';
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