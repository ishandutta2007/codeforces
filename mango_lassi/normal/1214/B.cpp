#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, b, g;
	cin >> b >> g >> n;
	b = min(b, n);
	g = min(g, n);
	// b <= i
	// g <= n-i
	int res = 0;
	for (int x = 0; x <= b; ++x) {
		int y = n - x;
		if (y > g) continue;
		++res;
	}
	cout << res << '\n';
}