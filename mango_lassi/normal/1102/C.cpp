#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x, y;
	cin >> n >> x >> y;
	int cou = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		if (v <= x) ++cou;
	}
	if (x > y) {
		cout << n << '\n';
	} else {
		cout << (cou + 1) / 2 << '\n';
	}
}