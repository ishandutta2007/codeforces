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
#include <ctime>

typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int last = -1, del = 0;
	if (a[0] != b[0]) {
		last = 0;
		del = a[0] - b[0];
	}
	if (del > 0) {
		cout << "NO\n";
		return;
	}
	for (int i = 1; i < n; i++) {
		if (del > 0) {
			cout << "NO\n";
			return;
		}
		if (a[i] != b[i]) {
			if (last == -1) {
				last = i, del = a[i] - b[i];
				continue;
			}
			if (last != i - 1 || a[i] - b[i] != del) {
				cout << "NO\n";
				return;
			} 
			last = i;
		}
	}
	if (del > 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}