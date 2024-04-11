#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	int cur = 0;
	bool st = true;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		if (v <= k) {
			++cur;
		} else {
			if (st) ans += cur;
			st = false;
			cur = 0;
		}
	}
	ans += cur;
	cout << ans << '\n';
}