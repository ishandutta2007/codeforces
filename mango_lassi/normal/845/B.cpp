#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

const int N = 3;
int nums [2 * N];
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string str;
	std::cin >> str;

	for (int i = 0; i < 2 * N; ++i) {
		nums[i] = (int)(str[i] - '0');
	}
	int first = 0;
	int second = 0;
	for (int i = 0; i < N; ++i) {
		first += nums[i];
		second += nums[i + N];
	}
	std::vector<int> change;
	int base = (first < second ? 0 : N);
	for (int i = 0; i < N; ++i) {
		change.push_back(9 - nums[i + base]);
		change.push_back(nums[i + N - base]);
	}
	std::sort(change.begin(), change.end());
	int diff = std::abs(first - second);
	int count = 0;
	while(diff > 0) {
		++count;
		diff -= change.back();
		change.pop_back();
	}
	std::cout << count << '\n';
}