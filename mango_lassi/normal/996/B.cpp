#include <iostream>

const int N = 1e5;
const int INF = 1e9 + 7;
long long len[N];

int main() {
	int n;
	std::cin >> n;
	long long skips = INF;
	for (int i = 0; i < n; ++i) {
		std::cin >> len[i];
		skips = std::min(skips, len[i] / n);
	}
	long long step = skips * n;
	for (int i = 0;;) {
		if (len[i] <= step) {
			std::cout << (i + 1) << '\n';
			break;
		}
		++step;
		++i;
		if (i == n) i = 0;
	}
}