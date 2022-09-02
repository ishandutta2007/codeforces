#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) cin >> a;
	vector<int> ord = as;
	sort(ord.begin(), ord.end());

	for (int i = 0; i < n; ++i) {
		if (as[i] != ord[i]) {
			int j = i;
			while(as[j] != ord[i]) ++j;
			for (int x = 0; i + x < j - x; ++x) swap(as[i + x], as[j - x]);
			break;
		}
	}

	for (int a : as) cout << a << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}