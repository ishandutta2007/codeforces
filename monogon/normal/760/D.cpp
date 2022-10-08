#include <iostream>
#include <algorithm>

int n;
int p[100001];
int best[100001];
int charges[100001];

int subtract(int index, int minutes) {
	for(int i = index; i >= 0; i--) {
		if(p[index] - p[i] >= minutes)
			return i;
	}
	return 0;
}

int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> p[i + 1];
	}
	best[0] = 0;
	for(int i = 1; i <= n; i++) {
		best[i] = std::min(20 + best[i - 1], std::min(50 + best[subtract(i, 90)], 120 + best[subtract(i, 1440)]));
		std::cout << best[i] - best[i - 1] << "\n";
	}
}