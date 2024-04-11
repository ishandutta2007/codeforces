#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
bool used[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for (int ti = 0; ti < t; ++ti) {
		int n;
		cin >> n;
		
		for (int i = 0; i < n; ++i) used[i] = 0;
		int x = -1;

		for (int i = 0; i < n; ++i) {
			int k;
			cin >> k;
			bool f = 0;
			for (int j = 0; j < k; ++j) {
				int t;
				cin >> t;
				if (!f && !used[t-1]) {
					f = 1;
					used[t-1] = 1;
				}
			}
			if (!f) x = i;
		}

		if (x == -1) cout << "OPTIMAL\n";
		else {
			cout << "IMPROVE\n";
			for (int y = 0; y < n; ++y) {
				if (! used[y]) {
					cout << x+1 << ' ' << y+1 << '\n';
					break;
				}
			}
		}
	}
}