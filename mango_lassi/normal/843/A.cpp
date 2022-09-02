#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> seq (n);
	std::vector<std::pair<int, int>> vals;
	for (int i = 0; i < n; ++i) {
		std::cin >> seq[i];
		vals.push_back({seq[i],i});
	}
	std::sort(vals.begin(), vals.end());
	for (int i = 0; i < n; ++i) {
		seq[vals[i].second] = i;
	}
	std::vector<int> team (n);
	for (int i = 0; i < n; ++i) {
		team[i] = -1;
	}
	std::vector<std::vector<int>> groups;
	for (int i = 0; i < n; ++i) {
		if (team[i] == -1) {
			int ind = groups.size();
			std::vector<int> gro;
			gro.push_back(i);
			team[i] = ind;
			int k = seq[i];
			while(k != i) {
				gro.push_back(k);
				team[k] = i;
				k = seq[k];
			}
			std::sort(gro.begin(), gro.end());
			groups.push_back(gro);
		}
	}
	std::cout << groups.size() << '\n';
	for (int i = 0; i < groups.size(); ++i) {
		std::cout << groups[i].size() << ' ';
		for (int j = 0; j < groups[i].size(); ++j) {
			std::cout << (groups[i][j] + 1) << ' ';
		}
		std::cout << '\n';
	}
}