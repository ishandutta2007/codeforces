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

	bool works = 1;
	for (int i = 0; i < n; ++i) works &= (as[i] == ord[i]);

	if (works) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}