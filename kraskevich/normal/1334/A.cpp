#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int n;
	cin >> n;
	int x = -1;
	int y = -1;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a < x) {
			ok = false;
		}
		if (b < y) {
			ok = false;
		}
		if ((a - x) < (b - y)) {
			ok = false;
		}
		x = a;
		y = b;
	}
	return ok;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	for (int rep = 0; rep < t; rep++) {
		cout << (solve() ? "YES" : "NO") << "\n";
	}
}