#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) cin >> a;
	sort(as.begin(), as.end());
	
	if (n & 1) {
		cout << "NO\n";
	} else {
		vector<int> bs(n);
		int h = n / 2;
		for (int i = 0; i < n / 2; ++i) {
			bs[2*i + 0] = as[n - 1 - i];
			bs[2*i + 1] = as[h - 1 - i];
		}

		bool works = 1;
		for (int i = 0; i < n; ++i) {
			int pre = (i + n-1) % n;
			int nxt = (i + 1) % n;
			if (bs[i] == bs[pre] || bs[i] == bs[nxt]) works = 0;
			if ((bs[i] < bs[pre]) != (bs[i] < bs[nxt])) works = 0;
		}
		if (works) {
			cout << "YES\n";
			for (int b : bs) cout << b << ' '; cout << '\n';
		} else {
			cout << "NO\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}