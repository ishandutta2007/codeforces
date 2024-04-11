#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	
	vector<int> vals(n);
	for (int& v : vals) cin >> v;

	vector<int> dp(2*n, n + 1), pre(2*n, -1);
	dp[0] = -n; dp[1] = -n;
	for (int i = 1; i < n; ++i) {
		int ind = 2*i;
		for (int x = 0; x <= 1; ++x) {
			int vi = vals[i] * (2*x - 1);
			for (int y = 0; y <= 1; ++y) {
				int vj = vals[i-1] * (2*y - 1);
				pair<int, int> pr = {dp[ind - 2 + y], vj};
				for (int s = 0; s <= 1; ++s, swap(pr.first, pr.second)) {
					if (pr.first <= vi && pr.second < dp[ind + x]) {
						dp[ind + x] = pr.second;
						pre[ind + x] = ind - 2 + y;
					}
				}
			}
		}
	}

	if (dp[2*n-1] <= n) {
		cout << "YES\n";
		int ind = 2*n-1;
		for (int i = n-1; i >= 0; --i) {
			if ((ind % 2) == 0) vals[i] *= -1;
			ind = pre[ind];
		}
		for (int v : vals) cout << v << ' '; cout << '\n';
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}