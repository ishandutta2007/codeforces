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

void solve() {
	int n;
	cin >> n;
	vector<lint> ar(n);
	For(i, n / 2)
		cin >> ar[i * 2 + 1];
	lint prv = 0;
	for (int i = 0; i < n; i += 2)
	{
		lint diff = ar[i + 1];
		lint res_s1 = -1, res_s2 = -1;
		for (lint a = 1; a * a < diff; ++a)
		{
			if (diff % a)
				continue;
			lint b = diff / a;
			if ((a + b) & 1)
				continue;
			lint s2 = (a + b) / 2;
			lint s1 = (b - a) / 2;
			if (s1 <= prv)
				continue;
			if (res_s2 == -1 || res_s2 > s2)
			{
				res_s1 = s1;
				res_s2 = s2;
			}
		}
		if (res_s1 == -1)
		{
			cout << "No\n";
			return;
		}
		ar[i] = res_s1 * res_s1 - prv * prv;
		if (ar[i + 1] != res_s2 * res_s2 - res_s1 * res_s1)
			throw;
		prv = res_s2;
	}
	cout << "Yes\n";
	For(i, n)
		cout << ar[i] << ' ';
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