#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	// Query returns (n1 - s1)(n2 - s2) = (sum le)(sum ri)

	// pair each alone with all before it
	// -> we are guaranteed to find the second value!!!
	// -> binary search where the first is

	int n;
	cin >> n;

	int x = -1;
	for (int i = 1; i < n; ++i) {
		cout << "? " << i << ' ' << 1 << endl;
		for (int j = 0; j < i; ++j) cout << j+1 << ' '; cout << endl;
		cout << i+1 << endl;

		ll f;
		cin >> f;
		if (f != 0) {
			x = i;
			break;
		}
	}

	vector<bool> works(n, 0);
	if (x != -1) {
		works[x] = 1;
		for (int y = x+1; y < n; ++y) {
			cout << "? " << 1 << ' ' << 1 << endl;
			cout << x+1 << endl;
			cout << y+1 << endl;

			ll f;
			cin >> f;
			if (f != 0) works[y] = 1;
		}

		int low = 0;
		int high = x-1;
		while(low != high) {
			int mid = (low + high) >> 1;
			cout << "? " << mid-low+1 << ' ' << 1 << endl;
			for (int j = low; j <= mid; ++j) cout << j+1 << ' '; cout << endl;
			cout << x+1 << endl;

			ll f;
			cin >> f;
			if (f != 0) high = mid;
			else low = mid + 1;
		}
		works[low] = 1;

	}

	vector<int> res;
	for (int i = 0; i < n; ++i) {
		if (! works[i]) res.push_back(i);
	}

	cout << "! " << res.size();
	for (auto v : res) cout << ' ' << v+1;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}