#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int evens = 0;
	int odds = 0;
	vector<int> vals(n);
	for (int i = 0; i < n; ++i) {
		cin >> vals[i];
		if (vals[i] & 1) ++odds;
		else ++evens;
	}
	if (evens > 0 && odds > 0) sort(vals.begin(), vals.end());
	for (auto v : vals) cout << v << ' '; cout << '\n';
}