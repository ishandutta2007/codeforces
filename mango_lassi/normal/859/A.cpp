#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> ranks (n);
	for (int i = 0; i < n; ++i) {
		std::cin >> ranks[i];
	}
	std::sort(ranks.begin(), ranks.end());
	std::cout << std::max(0, ranks[n-1]-25) << '\n';
}