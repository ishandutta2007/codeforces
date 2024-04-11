#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> vals(n);
	for(int& v : vals) cin >> v;

	if (vals[0] + vals[1] > vals[n-1]) cout << -1 << '\n';
	else cout << 1 << ' ' << 2 << ' ' << n << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}