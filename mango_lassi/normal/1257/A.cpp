#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
	int n, x, a, b;
	cin >> n >> x >> a >> b;
	int d = min(n-1, max(b - a, a - b) + x);
	cout << d << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}