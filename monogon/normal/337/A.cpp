#include <iostream>
#include <algorithm>
#include <climits>

int N, M;
int pieces[50];
int min = INT_MAX;

int main() {
	std::cin >> N >> M;
	for(int i = 0; i < M; i++) {
		std::cin >> pieces[i];
	}
	std::sort(pieces, pieces + M);
	for(int i = 0; i <= M - N; i++) {
		min = std::min(min, pieces[i + N - 1] - pieces[i]);
	}
	std::cout << min << std::endl;
}