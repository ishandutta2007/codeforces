#include <iostream>
#include <vector>
#include <algorithm>

int cou[32];

int main() {
	int n, q;
	std::cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		int j = -1;
		while(v) {
			++j;
			v >>= 1;
		}
		++cou[j];
	}
	for (int j = 0; j < q; ++j) {
		int v;
		std::cin >> v;
		int res = 0;
		for (int i = 30; i >= 0; --i) {
			int tmp = cou[i];
			int can = v >> i;
			int red = std::min(can, cou[i]);
			v -= red * (1<<i);
			res += red;
		}
		if (v != 0) {
			std::cout << -1 << '\n';
		} else {
			std::cout << res << '\n';
		}
	}
}