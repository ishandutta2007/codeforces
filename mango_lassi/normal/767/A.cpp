#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int N = 1e5;
bool ready[N];
int ind[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int> > snacks;
	for (int i = 0; i < n; ++i) {
		int s;
		std::cin >> s;
		snacks.push_back(std::make_pair(s, i));
	}
	std::sort(snacks.begin(), snacks.end());
	for (int i = 0; i < n; ++i) {
		ready[i] = false;
	}
	for (int i = n-1; i >= 0; --i) {
		ind[snacks[i].second] = i;
	}
	int max = n-1;
	for (int i = 0; i < n; ++i) {
		ready[ind[i]] = true;
		while((max >= 0) && (ready[max])) {
			std::cout << snacks[max].first << " ";
			--max;
		}
		std::cout << "\n";
	}
}