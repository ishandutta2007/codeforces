#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;
	long long sum = 0;
	int count = n;
	for (int i = 0; i < n; ++i) {
		int val;
		std::cin >> val;
		sum += val;
	}
	while(sum < k * count - count / 2) {
		++count;
		sum += k;
	}
	std::cout << count-n << '\n';
}