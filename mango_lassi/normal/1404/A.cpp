#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool solve() {
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	// We must have str[i] = str[i+k] and str[0 ... k-1] must have as many 0s as 1s

	for (int j = 0; j < k; ++j) {
		int zc = 0;
		int oc = 0;
		for (int i = j; i < n; i += k) {
			if (str[i] == '1') ++oc;
			else if (str[i] == '0') ++zc;
		}
		if (zc > 0 && oc > 0) return false;

		if (zc > 0) str[j] = '0';
		else if (oc > 0) str[j] = '1';
	}

	int zc = 0, oc = 0;
	for (int i = 0; i < k; ++i) {
		if (str[i] == '1') ++oc;
		else if (str[i] == '0') ++zc;
	}
	if (2*zc > k || 2*oc > k) return false;
	else return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		bool res = solve();
		if (! res) cout << "NO\n";
		else cout << "YES\n";
	}
}