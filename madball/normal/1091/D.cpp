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

const lint MOD = 998244353;
const int MAXN = (int)1e6 + 10;
lint fact[MAXN];

lint mul(lint a, lint b)
{
	return (a * b) % MOD;
}

void solve()
{
	For(i, MAXN)
		fact[i] = i ? mul(i, fact[i - 1]) : 1;
	lint n;
	cin >> n;
	lint res = 0;
	for (lint i = 1; i <= n; ++i)
		res = (mul(res, i) + fact[i] - 1) % MOD;
	cout << res + 1;
	/*vector<lint> ar(n);
	For(i, n)
		ar[i] = i;
	vector<lint> ar2;
	do
	{
		for (auto e : ar)
			cout << e << ' ';
		for (auto e : ar)
			ar2.push_back(e);
		cout << '\n';
	} while (next_permutation(all(ar)));
	lint sum = 0;
	cout << '\n' << '1' << ' ';
	for (lint i = n; i < sz(ar2); ++i)
	{
		sum += ar2[i];
		sum -= ar2[i - n];
		cout << (sum == 0 ? '1' : '0') << ' ';
		if (i % n == n - 2)
			cout << '\n';
	}*/
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