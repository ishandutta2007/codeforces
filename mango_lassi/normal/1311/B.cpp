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
		int n, k;
		cin >> n >> k;
		vector<int> arr(n), pos(n, 0);
		for (int& v : arr) cin >> v;
		for (int j = 0; j < k; ++j) {
			int i;
			cin >> i;
			pos[i-1] = 1;
		}

		bool can = 1;
		int mx = -1, cmx = -1;
		for (int i = 0; i < n; ++i) {
			cmx = max(cmx, arr[i]);
			if (arr[i] < mx) can = 0;
			if (! pos[i]) mx = cmx;
		}
		if (can) cout << "YES\n";
		else cout << "NO\n";
	}
}