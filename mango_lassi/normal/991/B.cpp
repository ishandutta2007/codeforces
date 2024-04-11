#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> vals (n);
	int tot = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> vals[i];
		tot += vals[i];
	}
	int res = 0;
	std::sort(vals.begin(), vals.end());
	for (int i = 0; 2 * tot / n < 9; ++i) {
		++res;
		tot += 5 - vals[i];
	}
	std::cout << res << '\n';
}