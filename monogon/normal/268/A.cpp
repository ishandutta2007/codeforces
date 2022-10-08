#include <iostream>

int N;
int h[30], g[30];
int sum;

int main() {
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> h[i] >> g[i];
	}
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			if(h[i] == g[j])
				sum++;
			if(h[j] == g[i])
				sum++;
		}
	}
	std::cout << sum;
}