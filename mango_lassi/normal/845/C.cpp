#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	
	std::vector<std::pair<int, int>> events;
	for (int i = 0; i < n; ++i) {
		int s, e;
		std::cin >> s >> e;
		events.push_back({s,1});
		events.push_back({e+1,-1});
	}
	std::sort(events.begin(), events.end());

	bool can = true;
	int count = 0;
	for (int i = 0; i < events.size(); ++i) {
		count += events[i].second;
		if (count > 2) {
			can = false;
			break;
		}
	}
	std::cout << (can ? "YES" : "NO") << '\n';
}