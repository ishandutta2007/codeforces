#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	bool can = false;
	for (int i = 0; i < m; ++i) {
		int k;
		std::cin >> k;
		std::vector<int> regs;
		for (int j = 0; j < k; ++j) {
			int r;
			std::cin >> r;
			if (r < 0) {
				regs.push_back(-3 * r + 1);
			} else {
				regs.push_back(3 * r);
			}
		}
		std::sort(regs.begin(), regs.end());
		bool same = false;
		for (int j = 1; j < regs.size(); ++j) {
			if (regs[j-1] + 1 == regs[j]) {
				same = true;
				break;
			}
		}
		if (! same) {
			can = true;
		}
	}
	if (can) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}