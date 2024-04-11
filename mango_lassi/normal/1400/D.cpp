#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> vals(n);
	for (int& v : vals) cin >> v;

	// O(n^2) ok
	
	ll res = 0;
	vector<int> cou(n+1, 0);

	for (int a = 0; a < n; ++a) {
		ll pairs = 0;
		for (int b = a+1; b < n; ++b) {
			if (vals[b] == vals[a]) res += pairs;
			pairs += cou[vals[b]];
		}
		cou[vals[a]] += 1;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}