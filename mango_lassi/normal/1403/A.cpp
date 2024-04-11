#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Choose all but first, all but last, then all

	int n;
	cin >> n;

	vector<ll> vals(n);
	for (ll& a : vals) cin >> a;

	if (n == 1) {
		cout << "1 1\n0\n";
		cout << "1 1\n0\n";
		cout << "1 1\n" << -vals[0] << "\n";
	} else {
		cout << 1 << ' ' << n-1 << '\n';
		for (int i = 0; i < n-1; ++i) {
			ll rem = ((vals[i] % n) + n) % n;
			ll add = rem * (n-1);
			cout << add << ' ';
			vals[i] += add;
		}
		cout << '\n';

		cout << 2 << ' ' << n << '\n';
		for (int i = 1; i < n; ++i) {
			ll rem = ((vals[i] % n) + n) % n;
			ll add = rem * (n-1);
			cout << add << ' ';
			vals[i] += add;
		}
		cout << '\n';

		cout << 1 << ' ' << n << '\n';
		for (int i = 0; i < n; ++i) cout << -vals[i] << ' '; cout << '\n';
	}
}