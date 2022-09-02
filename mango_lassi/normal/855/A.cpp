#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

const int N = 100;
bool is [N];
int main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<std::string, int>> names;
	for (int i = 0; i < n; ++i) {
		std::string str;
		std::cin >> str;
		names.push_back({str,i});
	}
	std::sort(names.begin(), names.end());
	for (int i = 1; i < n; ++i) {
		if (names[i].first == names[i-1].first) is[names[i].second] = true;
	}
	for (int i = 0; i < n; ++i) {
		std::cout << (is[i] ? "YES" : "NO") << '\n';
	}
}