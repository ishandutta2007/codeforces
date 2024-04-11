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
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		int mx1 = 0;
		int mx2 = 0;
		for (int i = 0; i < k1; ++i) {
			int v;
			cin >> v;
			mx1 = max(mx1, v);
		}
		for (int i = 0; i < k2; ++i) {
			int v;
			cin >> v;
			mx2 = max(mx2, v);
		}
		if (mx1 > mx2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}