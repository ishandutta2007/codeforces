#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> times;
	std::vector<int> rooms;
	times.push_back(0); // room visited at time t
	rooms.push_back(0); // last time we visited room i
	int roomc = 1;
	for (int i = 1; i <= n; ++i) {
		int t;
		std::cin >> t;
		if (rooms[times[t]] == t) {
			rooms[times[t]] = i;
			times.push_back(times[t]);
		} else {
			rooms.push_back(i);
			times.push_back(roomc);
			++roomc;
		}
	}
	std::cout << roomc << '\n';
}