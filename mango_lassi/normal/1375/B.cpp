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
		int h, w;
		cin >> h >> w;
		
		bool fail = false;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				int v;
				cin >> v;
				int maxv = (x > 0) + (y > 0) + (x < w-1) + (y < h-1);
				fail |= (v > maxv);
			}
		}

		if (fail) cout << "NO\n";
		else {
			cout << "YES\n";
			for (int y = 0; y < h; ++y) {
				for (int x = 0; x < w; ++x) {
					int maxv = (x > 0) + (y > 0) + (x < w-1) + (y < h-1);
					cout << maxv << ' ';
				}
				cout << '\n';
			}
		}
	}
}