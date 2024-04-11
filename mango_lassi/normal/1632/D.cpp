#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Change to extremely large primes
	// Greedy works
	// Loop left-to-right maintaining interval GCDs
	int res = 0;
	vector<int> pre(n, -1);
	vector<ll> gd(n, 0);
	for (int i = 0; i < n; ++i) {
		ll val;
		cin >> val;
		pre[i] = i - 1;
		for (int j = i; j >= 0; j = pre[j]) gd[j] = gcd(gd[j], val);
		for (int j = i; j >= 0; j = pre[j]) {
			while(pre[j] >= 0 && gd[pre[j]] == gd[j]) pre[j] = pre[pre[j]];
		}

		bool fail = 0;
		for (int b = i; b >= 0; b = pre[b]) {
			int a = pre[b] + 1;
			int d0 = (i+1 - b), d1 = (i+1 - a);
			fail |= (d0 <= gd[b] && gd[b] <= d1);
		}

		if (fail) {
			gd[i] = 1;
			pre[i] = -1;
			++res;
		}
		cout << res << ' ';
	}
	cout << '\n';
}