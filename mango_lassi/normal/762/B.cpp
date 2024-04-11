#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int a, b, c;
	std::cin >> a >> b >> c;

	std::vector<long long> as;
	std::vector<long long> bs;
	int m;
	std::cin >> m;
	long long cost; std::string port;
	for (int i = 0; i < m; ++i) {
		std::cin >> cost >> port;
		if (port == "USB") {
			as.push_back(cost);
		} else {
			bs.push_back(cost);
		}
	}
	int amount = 0;
	cost = 0;
	int asp = 0;
	int bsp = 0;
	std::sort(as.begin(), as.end());
	std::sort(bs.begin(), bs.end());
	while((a > 0) && (asp < as.size())) {
		++amount;
		--a;
		cost += as[asp];
		++asp;
	}
	while((b > 0) && (bsp < bs.size())) {
		++amount;
		--b;
		cost += bs[bsp];
		++bsp;
	}
	while(c > 0) {
		--c;
		if (asp < as.size()) {
			if (bsp < bs.size()) {
				if (as[asp] < bs[bsp]) {
					++amount;
					cost += as[asp];
					++asp;
				} else {
					++amount;
					cost += bs[bsp];
					++bsp;
				}
			} else {
				++amount;
				cost += as[asp];
				++asp;
			}
		} else if (bsp < bs.size()) {
			++amount;
			cost += bs[bsp];
			++bsp;
		} else {
			break;
		}
	}
	std::cout << amount << " " << cost << "\n";
}