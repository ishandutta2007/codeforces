#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, d;
	cin >> n >> d;

	vector<int> as(n);
	for (int& a : as) cin >> a;
	sort(as.begin(), as.end());

	bool succ = as.back() <= d;
	if (as[0] + as[1] <= d) succ = 1;
	cout << (succ ? "Yes" : "No") << '\n';
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}