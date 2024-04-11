#include <iostream>

const int N = 50;
int value [N];
int max [N+1]; // How much value the starting player can guarantee if they start at pie i

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> value[i];
	}
	int total = 0;
	max[n] = 0;
	for (int i = n-1; i >= 0; --i) {
		total += value[i];
		max[i] = std::max(max[i+1], total - max[i+1]);
	}
	std::cout << total - max[0] << ' ' << max[0] << '\n';
}