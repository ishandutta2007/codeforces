#include <bits/stdc++.h>
using namespace std;

long long solve() {
	int n;
	cin >> n;
	int x;
	cin >> x;
	long long s = 0;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	int res = 0;
	for (int i = 0; i < n; i++) {
		s += a[i];
		if (s >= (i + 1) * 1ll * x) {
			res = i + 1;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	for (int rep = 0; rep < t; rep++) {
		cout << solve() << "\n";
	}
}