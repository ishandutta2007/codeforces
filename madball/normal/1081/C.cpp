#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <ctime>
#include <functional>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <string>
#include <random>

using namespace std;

typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n)  for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

const lint MOD = 998244353;

lint mul(lint a, lint b)
{
	return (a * b) % MOD;
}

lint pw(lint a, lint b)
{
	return b == 0 ? 1 : b % 2 == 0 ? pw(mul(a, a), b / 2) : mul(a, pw(a, b - 1));
}

lint add(lint a, lint b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

void solve() {
	lint n, m, k;
	cin >> n >> m >> k;
	vector<vector<lint>> C(n + 1, vector<lint>(n + 1));
	C[0][0] = 1;
	for (int i = 1; i < sz(C); ++i)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	}
	cout << mul(mul(m, pw(m - 1, k)), C[n - 1][k]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}