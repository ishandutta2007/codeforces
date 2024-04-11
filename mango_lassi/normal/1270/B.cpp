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
		int n;
		cin >> n;
	
		vector<int> as(n);
		for (int& v : as) cin >> v;

		bool found = false;
		for (int i = 0; i+1 < n; ++i) {
			if (abs(as[i] - as[i+1]) >= 2) {
				cout << "YES\n";
				cout << i+1 << ' ' << i+2 << '\n';
				found = true;
				break;
			}
		}
		if (! found) cout << "NO\n";
	}
}