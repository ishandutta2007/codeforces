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

const int MOD = (int)1e9 + 7;
const int MAXK = 10005;
const int LOG = 52;

void inc(int& a, int b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
}

int mul(int a, int b)
{
	return ((lint)a * b) % MOD;
}

int pw(int a, int b)
{
	return b == 0 ? 1 : b & 1 ? mul(a, pw(a, b - 1)) : pw(mul(a, a), b / 2);
}

int ans[LOG][LOG][MAXK];
int inv[LOG + 1];

void precalc()
{
	For(i, LOG + 1)
		inv[i] = pw(i, MOD - 2);
	For(from, LOG)
	{
		ans[from][from][0] = 1;
		For(k, MAXK - 1)
		{
			For(cur, from + 1)
				inc(ans[from][cur][k + 1], mul(ans[from][cur][k], inv[cur + 1]));
			for (int i = from - 1; i >= 0; --i)
				inc(ans[from][i][k + 1], ans[from][i + 1][k + 1]);
		}
	}
}

void solve()
{
	precalc();
	lint n;
	int k;
	cin >> n >> k;
	int res = 1;
	vector<pair<lint, int>> decomp;
	for (lint i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			int cnt = 0;
			while (n % i == 0)
			{
				n /= i;
				++cnt;
			}
			decomp.emplace_back(i, cnt);
		}
	}
	if (n > 1)
		decomp.emplace_back(n, 1);
	for (auto e : decomp)
	{
		int cur = 0;
		For(i, e.second + 1)
		{
			int cur_pow = pw((int)(e.first % MOD), i);
			inc(cur, mul(cur_pow, ans[e.second][i][k]));
		}
		res = mul(res, cur);
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