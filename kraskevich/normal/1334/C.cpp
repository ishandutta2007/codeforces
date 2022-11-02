#include <bits/stdc++.h>
using namespace std;
 
long long solve() {
	int n;
	cin >> n;
	vector<long long> a(n);
	vector<long long> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	if (n == 1) {
		return a[0];
	}
	long long s = 0;
	for (int i = 0; i < n; i++) {
		int j = (i == 0) ? n - 1 : i - 1;
		s += max(0ll, a[i] - b[j]);
	}
	long long delta = 1e18;
	for (int i = 0; i < n; i++) {
	    long long x = a[i];
	    int j = (i == 0) ? n - 1 : i - 1;
	    long long y = max(0ll, a[i] - b[j]);
	    delta = min(delta, x - y);
	}
	return s + delta;
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