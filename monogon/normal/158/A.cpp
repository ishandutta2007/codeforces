
#include <iostream>
#include <algorithm>

int N, K;
int score[50];
int sum = 0;

int main() {
	std::cin >> N >> K;
	for(int i = 0; i < N; i++) {
		std::cin >> score[i];
	}
	std::sort(score, score + N);
	int best = std::max(1, score[N - K]);
	for(int i = 0; i < N; i++)
		if(score[i] >= best)
			sum++;
	std::cout << sum << std::endl;
}