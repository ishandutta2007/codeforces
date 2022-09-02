#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int m, k;
		cin >> m >> k;
		if ((m - k) % 2 != 0 || m < (ll)k * k) cout << "NO\n";
		else cout << "YES\n";
	}
}