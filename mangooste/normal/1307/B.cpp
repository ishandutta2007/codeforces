#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

const int N = 1e5 + 2;

ll a[N];

signed main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		ll x;
		cin >> n >> x;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		bool can = false;
		for (int i = 0; i < n; i++) {
			if (a[i] == x) {
				can = true;
				cout << "1\n";
				break;
			}
		}
		if (can) 
			continue;
		sort(a, a + n);
		reverse(a, a + n);
		if (a[0] == x)
			cout << "1\n";
		else if (a[0] > x)
			cout << "2\n";
		else
			cout << (x + a[0] - 1) / a[0] << '\n';
	}
}