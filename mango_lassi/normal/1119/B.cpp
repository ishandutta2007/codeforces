#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, h;
	cin >> n >> h;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	int res = 0;
	vector<int> bins;
	for (int j = 0; j < n; ++j) {
		bins.push_back(a[j]);
		sort(bins.begin(), bins.end());

		int req = 0;
		for (int i = j; i >= 0; i -= 2) {
			req += bins[i];
		}
		if (req <= h) res = j+1;
		else break;
	}
	cout << res << '\n';
}