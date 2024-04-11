#include <iostream>

const int inf = 1e9 + 7;
const int N = 100;
int nums [N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> nums[i];
	}
	int min = inf;
	int max = -inf;
	for (int i = 0; i < k; ++i) {
		int num;
		std::cin >> num;
		min = std::min(num, min);
		max = std::max(num, max);
	}
	if (min != max) {
		std::cout << "Yes\n";
	} else {
		for (int i = 0; i < n; ++i) {
			if (nums[i] == 0) nums[i] = min;
		}
		bool inc = true;
		for (int i = 1; i < n; ++i) {
			if (nums[i] <= nums[i-1]) {
				inc = false;
				break;
			}
		}
		if (inc) {
			std::cout << "No\n";
		} else {
			std::cout << "Yes\n";
		}
	}
}