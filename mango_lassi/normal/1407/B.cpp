#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve() {
	int n;
	cin >> n;

	vector<int> vals(n);
	for (int& v : vals) cin >> v;

	// O(n^2) is fine, so we can just brute-force
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		int ind = 0;
		for (int j = 1; j < n-i; ++j) {
			if (gcd(cur, vals[ind]) < gcd(cur, vals[j])) ind = j;
		}
		swap(vals[ind], vals.back());
		cur = gcd(cur, vals.back());
		cout << vals.back() << ' ';
		vals.pop_back();
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}