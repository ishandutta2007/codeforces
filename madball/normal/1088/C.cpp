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
	For(i, n)
		cin >> ar[i];
	lint added = 0;
	cout << n + 1 << '\n';
	for (int i = n - 1; i >= 0; --i)
	{
		lint add = i - ((ar[i] + added) % n);
		if (add < 0)
			add += n;
		added += add;
		cout << 1 << ' ' << i + 1 << ' ' << add << '\n';
	}
	cout << 2 << ' ' << n << ' ' << n << '\n';
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