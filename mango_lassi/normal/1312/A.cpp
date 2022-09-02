#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		cin >> n >> m;
		cout << (n % m == 0 ? "YES" : "NO") << '\n';
	}
}