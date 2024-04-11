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

const int MAXN = 5050;
vector<int> ar[MAXN];
int mn[MAXN];

void solve()
{
	int n, m;
	cin >> n >> m;
	For(i, m)
	{
		int a, b;
		cin >> a >> b;
		ar[a - 1].push_back(b - 1);
	}
	For(i, n)
	{
		mn[i] = i ? i - 1 : n - 1;
		for (auto e : ar[i])
		{
			if (e >= i && mn[i] < i)
				mn[i] = e;
			else if (e < i && mn[i] >= i);
			else mn[i] = min(mn[i], e);
		}
	}
	For(i, n)
	{
		lint res = 0;
		For(j_, n)
		{
			int j = (i + j_) % n;
			if (sz(ar[j]))
				res = max(res, j_ + (lint)n * (sz(ar[j]) - 1) + (mn[j] - j + n) % n);
		}
		cout << res << ' ';
	}
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