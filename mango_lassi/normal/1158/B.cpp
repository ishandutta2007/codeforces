#include <iostream>
#include <vector>
using namespace std;

int count(const string& str) {
	int n = str.size();
	for (int l = 1; l <= n; ++l) {
		for (int i = 0; i+l <= n; ++i) {
			bool fail = false;
			for (int j = 0; j+l <= n; ++j) {
				if (j == i) continue;
				bool match = true;
				for (int z = 0; z < l; ++z) {
					if (str[i+z] != str[j+z]) match = false;
				}
				if (match == true) fail = true;
			}
			if (! fail) return l;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << '0';
		for (int i = 1; i < n; ++i) cout << '1';
		cout << '\n';
	} else {

		int d = (n - k) / 2;
		int l0 = (d+2) / 2;
		int l1 = (d+1) / 2;
		string res;
		while(res.size() < n) {
			for (int i = 0; (i < l0) && (res.size() < n); ++i) {
				res.push_back('0');
			}
			for (int i = 0; (i < l1) && (res.size() < n); ++i) {
				res.push_back('1');
			}
		}
		cout << res << '\n';
		// cout << count(res) << '\n';
	}
}