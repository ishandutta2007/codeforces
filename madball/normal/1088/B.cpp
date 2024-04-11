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
	int n, k;
	cin >> n >> k;
	vector<int> ar;
	For(i, n)
	{
		int a;
		cin >> a;
		if (a)
			ar.push_back(a);
	}
	sort(all(ar));
	ar.resize(unique(all(ar)) - ar.begin());
	for (int i = sz(ar) - 1; i > 0; --i)
		ar[i] -= ar[i - 1];
	while (sz(ar) < k)
		ar.push_back(0);
	For(i, k)
		cout << ar[i] << '\n';
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