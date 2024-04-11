#include <iostream>

int main() {
	int n;
	long long a, b;
	std::cin >> n >> a >> b;
	int segs = 0;
	bool zero_streak = false;
	for (int i = 0; i < n; ++i) {
		char c;
		std::cin >> c;
		if (c == '0') {
			if (! zero_streak) {
				zero_streak = true;
				++segs;
			}
		} else if (c == '1') {
			zero_streak = false;
		}
	}
	if (segs == 0) {
		std::cout << "0\n";
	} else {
		long long res = b + std::min(a, b) * (segs - 1);
		std::cout << res << '\n';
	}
}