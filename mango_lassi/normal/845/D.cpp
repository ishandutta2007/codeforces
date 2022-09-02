#include <iostream>
#include <vector>

const int inf = 1e9;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::vector<int> limit;
	limit.push_back(inf);
	int bans = 0;
	int skip = 0;
	int speed = 0;
	for (int i = 0; i < n; ++i) {
		int t;
		std::cin >> t;
		if (t == 1) {
			std::cin >> speed;
			while (limit.back() < speed) {
				++skip;
				limit.pop_back();
			}
		} else if (t == 2) {
			skip += bans;
			bans = 0;
		} else if (t == 3) {
			int val;
			std::cin >> val;
			if (val < speed) {
				++skip;
			} else {
				limit.push_back(val);
			}
		} else if (t == 4) {
			bans = 0;
		} else if (t == 5) {
			limit.push_back(inf);
		} else if (t == 6) {
			++bans;
		}
	}
	std::cout << skip << '\n';
}