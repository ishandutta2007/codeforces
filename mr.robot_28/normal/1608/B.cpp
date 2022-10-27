#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) (int)a.size()
const int N = 3e5 + 100;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		if (abs(a - b) > 1 || a + b > n - 2) {
			cout << -1 << "\n";
			continue;
		}
		if (a > b) {
			cout << 1 << " ";
			int it1 = 2, it2 = n;
			int c = a + b;
			for (int i = 1; i < c; i++) {
				if (a > b) {
					cout << it2-- << " ";
					a--;
				}
				else {
					b--;
					cout << it1++ << " ";
				}
			}
			while (it2 >= it1) {
				cout << it2-- << " ";
			}
		}
		else if (b > a) {
			cout << n << " ";
			int it1 = 1, it2 = n - 1;
			int c = a + b;
			for (int i = 1; i < c; i++) {
				if (b > a) {
					b--;
					cout << it1++ << " ";
				}
				else {
					a--;
					cout << it2-- << " ";
				}
			}
			while (it1 <= it2) {
				cout << it1++ << " ";
			}
		}
		else {
			cout << n << " ";
			int it1 = 1, it2 = n - 1;
			int c = a + b;
			for (int i = 1; i < c; i++) {
				if (b >= a) {
					b--;
					cout << it1++ << " ";
				}
				else {
					a--;
					cout << it2-- << " ";
				}
			}
			while (it2 >= it1) {
				cout << it2-- << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}