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
		int n;
		ll m;
		cin >> n >> m;
		ll sum = 0;
		for (int i = 0; i < n; ++i) {
			ll v;
			cin >> v;
			sum += v;
		}
		cout << min(sum, m) << '\n';
	}
}