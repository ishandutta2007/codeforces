#include <iostream>
#include <algorithm>

using namespace std;

signed main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		if (n < 4)
			cout << 4 - n << '\n';
		else
			cout << n % 2 << '\n';
	}
	return 0;
}