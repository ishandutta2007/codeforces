#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve() {
	string a, b;
	cin >> a >> b;
	if (a.size() > b.size()) swap(a, b);
	int n = a.size(), m = b.size();
	
	int k = n*m / gcd(n, m);
	string res(k, '_');
	for (int i = 0; i < k; ++i) res[i] = a[i % n];

	bool fail = 0;
	for (int i = 0; i < k; ++i) {
		if (res[i] != b[i % m]) fail = 1;
	}
	if (fail) {
		cout << -1 << '\n';
	} else {
		cout << res << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}