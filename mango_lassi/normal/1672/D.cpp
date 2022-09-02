#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> as(n), bs(n);
	for (int& a : as) cin >> a;
	for (int& b : bs) cin >> b;

	// Go end to start
	vector<int> cou(n + 1, 0);
	for (int i = 0, j = 0; i < n && j < n;) {
		if (cou[bs[j]] > 0 && j + 1 < n && bs[j + 1] == bs[j]) {
			--cou[bs[j]];
			++j;
		} else if (bs[j] != as[i]) {
			++cou[as[i]];
			++i;
		} else {
			++i;
			++j;
		}
	}

	bool works = 1;
	for (int v : cou) works &= (v == 0);

	if (works) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}