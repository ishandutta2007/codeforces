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
	n*=2;

	vector<int> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];
	sort(vals.begin(), vals.end());
	if (vals[0] == vals[n-1]) cout << -1 << "\n";
	else {
		for (auto v :vals) cout << v << ' '; cout << '\n';
	}
}