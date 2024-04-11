#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
	std::vector<std::pair<int, int>> els;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, x;
		std::cin >> a >> x;
		els.push_back({a, -x});
	}
	int m;
	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		int b, x;
		std::cin >> b >> x;
		els.push_back({b, -x});
	}
	std::sort(els.begin(), els.end());
	long long res = 0;
	for (int i = 0; i < els.size(); ++i) {
		if (i > 0 && els[i - 1].first == els[i].first) continue;
		res += -els[i].second;
	}
	std::cout << res << '\n';
}