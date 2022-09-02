#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const int N = 200000;
bool used [N];
int price [N];
int front [N];
int back  [N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> price[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> front[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> back[i];
	}

	int inds [4];
	for (int i = 0; i < 4; ++i) {
		inds[i] = 0;
	}
	std::vector<std::pair<int, int> > shirts [4];
	
	for (int i = 0; i < n; ++i) {
		shirts[front[i]].push_back(std::make_pair(price[i], i));
		shirts[back[i]].push_back(std::make_pair(price[i], i));
	}
	
	std::sort(shirts[1].begin(), shirts[1].end());
	std::sort(shirts[2].begin(), shirts[2].end());
	std::sort(shirts[3].begin(), shirts[3].end());

	int m;
	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		int c;
		std::cin >> c;
		int ind = inds[c];
		while((ind < shirts[c].size()) && (used[shirts[c][ind].second])) {
			++ind;
		}
		if (ind >= shirts[c].size()) {
			std::cout << "-1\n";
		} else {
			used[shirts[c][ind].second] = true;
			std::cout << shirts[c][ind].first << ' ';
		}
		inds[c] = ind;
	}
	std::cout << '\n';
}