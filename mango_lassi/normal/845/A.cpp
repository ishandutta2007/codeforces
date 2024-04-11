#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::vector<int> players (2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		std::cin >> players[i];
	}
	std::sort(players.begin(), players.end());
	if (players[n] == players[n-1]) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
	}
}