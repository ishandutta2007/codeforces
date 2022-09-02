#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> as(n);
	int ones = 0;
	for (int& a : as) {
		cin >> a;
		ones += a;
	}

	for (int qi = 0; qi < q; ++qi) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			--x;

			if (as[x]) --ones;
			else ++ones;
			as[x] ^= 1;
		} else {
			int k;
			cin >> k;
			if (ones >= k) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}