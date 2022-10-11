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
#define int ll

using namespace std;

void solve() {
	int n;
	cin >> n;
	int last_close = 0;
	int last_open = 0;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		if (last_close == 0 || last_close > r) {
			last_close = r;
		}
		if (last_open == 0 || last_open < l) {
			last_open = l;
		}
	}
	cout << max(0ll, last_open - last_close) << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}