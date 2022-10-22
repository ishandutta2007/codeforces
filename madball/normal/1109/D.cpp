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
const int MAXN = (int)1e6 + 10;

int add(int a, int b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

void relax(int& a, int b)
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
	return b == 0 ? 1 : b % 2 ? mul(a, pw(a, b - 1)) : pw(mul(a, a), b / 2);
}

int inv(int a)
{
	return pw(a, MOD - 2);
}

int fact[MAXN];
int ifact[MAXN];

int c(int n, int k)
{
	return k < 0 || k > n ? 0 : mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int n_pow[MAXN];
int m_pow[MAXN];

void solve()
{
	int n, m;
	cin >> n >> m;
	n_pow[0] = m_pow[0] = 1;
	for (int i = 1; i < MAXN; ++i)
	{
		n_pow[i] = mul(n_pow[i - 1], n);
		m_pow[i] = mul(m_pow[i - 1], m);
	}
	int res = 0;
	for (int len = 1; len < n && len <= m; ++len)
	{
		int weights = c(m - 1, len - 1);
		int order = mul(fact[n - 2], ifact[n - 1 - len]);
		int other = len == n - 1 ? 1 : mul(len + 1, n_pow[n - 2 - len]);
		int other_w = m_pow[n - 1 - len];
		relax(res, mul(mul(weights, order), mul(other, other_w)));
	}
	cout << res << '\n';
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	fact[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		fact[i] = mul(fact[i - 1], i);
	ifact[MAXN - 1] = inv(fact[MAXN - 1]);
	for (int i = MAXN - 2; i >= 0; --i)
		ifact[i] = mul(ifact[i + 1], i + 1);
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}