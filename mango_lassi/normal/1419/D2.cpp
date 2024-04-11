#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> as(n);
	for (int& a : as) cin >> a;

	sort(as.begin(), as.end());
	reverse(as.begin(), as.end());

	int ind = 0;
	vector<ll> res(n, -1);
	for (int i = 0; i < n; ++i) {
		res[ind] = as[i];

		ind += 2;
		if (ind == n) --ind;
		else if (ind > n) ind = 1;
	}
	
	int ans = 0;
	for (int i = 1; i+1 < n; ++i) {
		if (res[i] < res[i-1] && res[i] < res[i+1]) ++ans;
	}

	cout << ans << '\n';
	for (auto v : res) cout << v << ' '; cout << '\n';

	// 4
	// 3 2 2 1

	// 3 . 2 .
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}