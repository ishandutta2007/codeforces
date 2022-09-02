#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		ll a, b;
		cin >> a >> b;
		ll d = abs(b - a);

		if (a == b) cout << 0 << '\n';
		else if (b < a) {
			if (d & 1) cout << 2 << '\n';
			else cout << 1 << '\n';
		} else {
			if (d & 1) cout << 1 << '\n';
			else cout << 2 << '\n';
		}
	}
}