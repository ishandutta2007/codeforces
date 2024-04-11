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
		int n;
		cin >> n;

		if (n == 1) cout << -1 << '\n';
		else {
			cout << 4;
			for (int i = 0; i < n-1; ++i) cout << 3;
			cout << '\n';
		}
	}
}