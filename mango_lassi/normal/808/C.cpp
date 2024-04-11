#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int N = 100;
int size [N];
int used [N];
std::vector<std::pair<int, int> > order;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, w;
	std::cin >> n >> w;

	int need = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> size[i];
		order.push_back(std::make_pair(size[i], i));
		used[i] = (size[i] + 1) / 2;
		need += used[i];
	}
	std::sort(order.begin(), order.end());
	if (need <= w) {
		w -= need;
		for (int i = n-1; i >= 0; --i) {
			int ind = order[i].second;
			int diff = std::min(size[ind] - used[ind], w);
			used[ind]+= diff;
			w -= diff;
		}
		for (int i = 0; i < n; ++i) {
			std::cout << used[i] << ' ';
		}
		std::cout << '\n';
	} else {
		std::cout << "-1\n";
	}
}