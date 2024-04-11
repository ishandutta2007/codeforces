#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n; long long s;
	std::cin >> n >> s;
	long long base = 0;
	long long fs = 0;
	long long ss = 0;
	std::vector<std::pair<long long, long long>> first;
	std::vector<std::pair<long long, long long>> second;
	for (int i = 0; i < n; ++i) {
		long long c, a, b;
		std::cin >> c >> a >> b;
		if (a > b) {
			base += c*a;
			fs += c;
			first.push_back({a-b,c});
		} else {
			base += c*b;
			ss += c;
			second.push_back({b-a,c});
		}
	}
	std::sort(first.begin(), first.end());
	std::sort(second.begin(), second.end());
	fs %= s;
	ss %= s;
	if (fs + ss > s) {
		std::cout << base << '\n';
	} else {
		long long offer = 0;
		for (int i = 0; fs > 0; ++i) {
			long long count = std::min(fs, first[i].second);
			offer -= first[i].first * count;
			fs -= count;
		}
		long long other = 0;
		for (int i = 0; ss > 0; ++i) {
			long long count = std::min(ss, second[i].second);
			other -= second[i].first * count;
			ss -= count;
		}
		std::cout << (base + std::max(offer, other)) << '\n';
	}
}