#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	cout << ((n*m + 1) / 2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}