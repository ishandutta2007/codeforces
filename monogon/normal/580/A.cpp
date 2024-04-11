#include <iostream>

int N;
int p[100000];
int count;
int max;

int main() {
	std::cin >> N;
	if(N == 0) std::cout << 0 << std::endl;
	std::cin >> p[0];
	for(int i = 1; i < N; i++) {
		std::cin >> p[i];
		if(p[i] >= p[i - 1]) {
			count++;
			if(count > max)
				max = count;
		}else
			count = 0;
	}
	std::cout << max + 1 << std::endl;
}