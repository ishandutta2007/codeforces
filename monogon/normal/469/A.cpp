#include <iostream>

bool level[100];
int a;
int N, p, q;

int main() {
	std::cin >> N;
	std::cin >> p;
	for(int i = 0; i < p; i++) {
		std::cin >> a;
		level[a - 1] = 1;
	}
	std::cin >> q;
	for(int i = 0; i < q; i++) {
		std::cin >> a;
		level[a - 1] = 1;
	}
	bool able = true;
	for(int i = 0; i < N; i++) {
		if(!level[i]) {
			able = false;
			break;
		}
	}
	std::cout << (able ? "I become the guy." : "Oh, my keyboard!") << std::endl;
}