#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i != n; ++i) cin >> a[i];
		partial_sum(a.begin(), a.end(), a.begin());
		bool ans = true;
		for (int i = 0; ans && i != n - 1; ++i) if (a[i] >= a[n - 1]) ans = false;
		if (ans) {
			long long b = a[0];
			for (int i = 1; ans && i != n; ++i) {
				if (a[i] - b >= a[n - 1]) ans = false;
				b = min(b, a[i]);
			}
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}