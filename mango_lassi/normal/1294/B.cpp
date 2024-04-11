#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		int n;
		cin >> n;
		vector<pair<int, int>> pkg(n);
		for (auto& pr : pkg) cin >> pr.first >> pr.second;
		sort(pkg.begin(), pkg.end());

		int x = 0;
		int y = 0;
		string res;
		bool fail = false;
		for (int i = 0; (! fail) && i < n; ++i) {
			if (pkg[i].first < x || pkg[i].second < y) fail = true;
			else {
				while(x < pkg[i].first) {
					res.push_back('R');
					++x;
				}
				while(y < pkg[i].second) {
					res.push_back('U');
					++y;
				}
			}
		}
		if (fail) cout << "NO\n";
		else cout << "YES\n" << res << '\n';
	}
}