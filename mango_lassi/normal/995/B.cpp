#include <iostream>
#include <vector>

const int N = 200;
int val[N];

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < 2*n; ++i) {
		std::cin >> val[i];
	}
	int res = 0;
	for (int i = 0; i < 2 * n; i += 2) {
		for (int j = 2 * n - 1; j > i + 1; --j) {
			if (val[j] == val[i]) {
				std::swap(val[j], val[j-1]);
				++res;
			}
		}
	}
	std::cout << res << '\n';
}