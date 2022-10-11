#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <cstdio>

typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n <= 2 || m < n) {
		cout << "-1\n";
		return;
	}
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += a[i];
	}
	cout << 2 * s << '\n';
	for (int i = 0; i < n - 1; i++) {
		cout << i + 1 << ' ' << i + 2 << '\n';
	}
	cout << n << ' ' << 1 << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}