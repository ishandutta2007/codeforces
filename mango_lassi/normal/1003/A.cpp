#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> els(n);	
	for (int i = 0; i < n; ++i) std::cin >> els[i];
	std::sort(els.begin(), els.end());
	int res = 1;
	int cou = 1;
	for (int i = 1; i < n; ++i) {
		if (els[i] == els[i-1]) {
			++cou;
		} else {
			cou = 1;
		}
		res = std::max(res, cou);
	}
	std::cout << res << '\n';
}