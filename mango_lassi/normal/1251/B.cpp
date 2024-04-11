#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	int odds = 0, ones = 0, zeros = 0;
	for (int j = 0; j < n; ++j) {
		string str;
		cin >> str;
		for (auto c : str) {
			if (c == '0') ++zeros;
			else if (c == '1') ++ones;
		}
		if (str.size() & 1) ++odds;
	}
	if ((ones % 2 + zeros % 2) <= odds) {
		cout << n << '\n';
	} else {
		cout << n-1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}