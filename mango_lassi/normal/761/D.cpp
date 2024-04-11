#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int inf = 1e9 + 7;
const int N = 1e5;
int bs [N];
int as [N];

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n, mn, mx;
	std::cin >> n >> mn >> mx;
	
	std::vector<std::pair<int, int> > order;
	for (int i = 0; i < n; ++i) {
		std::cin >> as[i];
	}
	for (int i = 0; i < n; ++i) {
		int ord;
		std::cin >> ord;
		order.push_back(std::make_pair(ord, i));
	}
	std::sort(order.begin(), order.end());
	bool possible = true;
	int high = inf;
	for (int i = n-1; i >= 0; --i) {
		int ind = order[i].second;
		int a = as[ind];
		// We need high > b - a <=> high + a > b
		int b = min(high + a - 1, mx);
		high = b - a;
		if (b < mn) {
			possible = false;
			break;
		}
		bs[ind] = b;
	}
	if (possible) {
		for (int i = 0; i < n; ++i) {
			std::cout << bs[i] << " ";
		}
		std::cout << "\n";
	} else {
		std::cout << "-1\n";
	}
}