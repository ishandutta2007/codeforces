#include <iostream>
#include <climits>

int N;
int p[100];
int max, min = INT_MAX;
int maxIndex, minIndex;

int main() {
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> p[i];
		if(p[i] <= min) {
			minIndex = i;
			min = p[i];
		}
		if(p[i] > max) {
			maxIndex = i;
			max = p[i];
		}
	}
	std::cout << maxIndex + (N - minIndex - 1) - (maxIndex > minIndex) << std::endl;
}