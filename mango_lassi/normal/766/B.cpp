#include <iostream>
#include <vector>
#include <algorithm>


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> lens;
	for (int i = 0; i < n; ++i) {
		int k;
		std::cin >> k;
		lens.push_back(k);
	}
	std::sort(lens.begin(), lens.end());
	bool pos = false;
	for (int i = lens.size()-1; i >= 2; --i) {
		if ((lens[i-1] + lens[i-2]) > lens[i]) {
			pos = true;
			break;
		}
	}
	if (pos) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}