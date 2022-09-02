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
		ll v;
		cin >> v;
		if (14 <= v && 1 <= (v % 14) && (v % 14) <= 6) cout << "YES\n";
		else cout << "NO\n";
	}
}