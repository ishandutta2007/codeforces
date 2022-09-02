#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <utility>

const int N = 50000;
int next [N];
int value [N];

void ask(int i) {
	if (next[i] == -2) {
		std::cout << "? " << (i+1) << std::endl;
		std::cin >> value[i] >> next[i];
		if (next[i] != -1) --next[i];
	}
}

int solve(int n, int start, int x) {
	for (int i = 0; i < n; ++i) {
		next[i] = -2;
	}
	std::vector<std::pair<int, int>> guesses;
	std::vector<int> order (n-1);
	for (int i = 1; i < n; ++i) {
		order[i-1] = i;
	}
	std::random_shuffle(order.begin(), order.end());
	ask(start);
	for (int i = 0; i < std::min(1000, (int)order.size()); ++i) {
		int j = order[i];
		ask(j);
		guesses.push_back({value[j], j});
	}
	std::sort(guesses.begin(), guesses.end());
	int ind = start;
	for (int i = 0; i < guesses.size(); ++i) {
		if (guesses[i].first > x) {
			break;
		} else {
			ind = guesses[i].second;
		}
	}
	while(value[ind] < x) {
		if (next[ind] == -1) {
			break;
		}
		ind = next[ind];
		ask(ind);
	}
	if (value[ind] < x) {
		return -1;
	} else {
		return value[ind];
	}
}

int main() {
	int n, start, x;
	srand(21749127);
	std::cin >> n >> start >> x;
	--start;
	int val = solve(n, start, x);
	if (val == -1) {
		std::cout << "! -1" << std::endl;
	} else {
		std::cout << "! " << val << std::endl;
	}
}