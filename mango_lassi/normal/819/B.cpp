#include <iostream>
#include <algorithm>

const int N = 1e6;
long long ddx [2 * N + 5];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	long long init = 0;
	for (int i = 1; i <= n; ++i) {
		int num;
		std::cin >> num;
		init += std::abs(i - num);
		if (num <= i) {
			// Initially the num moves below the line
			++ddx[0];
			// When the num goes past the ledge
			// Num is at i, ledge is at n, we are there after n-i moves,
			--ddx[n-i];
			ddx[n-i] += std::abs(1-num) - std::abs(n-num);
			ddx[n-i+1] += std::abs(n-num) - std::abs(1-num);
			--ddx[n-i+1];
			ddx[n-i+num] += 2;
		} else {
			--ddx[0];
			ddx[num-i] += 2;
			--ddx[n-i];
			ddx[n-i] += std::abs(1-num) - std::abs(n-num);
			ddx[n-i+1] += std::abs(n-num) - std::abs(1-num);
			--ddx[n-i+1];
		}
	}

	int min_rot = 0;
	long long min_val = init;


	long long dx = ddx[0];
	for (int i = 1; i < n; ++i) {
		init += dx;
		dx += ddx[i];
		if (init < min_val) {
			min_val = init;
			min_rot = i;
		}
	}
	std::cout << min_val << ' ' << min_rot << '\n';
}