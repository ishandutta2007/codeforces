#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e9;

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) {
		cin >> a;
		--a;
	}

	int t = 0;
	for (int i = 0; i < n; ++i) {
		if (as[i] == i) {
			if (t & 1) ++t;
		} else {
			if (! (t & 1)) ++t;
		}
	}
	if (t == 0) cout << 0 << '\n';
	else if (t <= 2) cout << 1 << '\n';
	else cout << 2 << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}
}