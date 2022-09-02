#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> vals(n);
	for (int& v : vals) cin >> v;
	sort(vals.begin(), vals.end());
	if (vals[0] == vals[n-1]) cout << n << '\n';
	else cout << 1 << '\n'; // Always take two with maximum sum
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}