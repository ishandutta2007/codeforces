#include <iostream>

const int inf = 1e9 + 7;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	int ce = inf;
	int cs = 0;
	for (int i = 0; i < n; ++i) {
		int a, b;
		std::cin >> a >> b;
		if (a > cs) {
			cs = a;
		}
		if (b < ce) {
			ce = b;
		}
	}
	// 
	int m;
	std::cin >> m;
	int pe = inf;
	int ps = 0;
	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		if (a > ps) {
			ps = a;
		}
		if (b < pe) {
			pe = b;
		}
	}
	std::cout << std::max(0, std::max(ps - ce, cs - pe)) << '\n';
	
}