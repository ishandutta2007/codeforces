#include <iostream>
#include <algorithm>

long long N;
long long a[100001];
long long best[100001];
long long num;
long long max = 0;

int main() {
	std::cin >> N;
	for(long long i = 0; i < N; i++) {
		std::cin >> num;
		a[num]++;
		max = std::max(max, num);
	}
	best[0] = 0;
	best[1] = a[1];
	for(long long i = 2; i <= max; i++) {
		best[i] = std::max(i * a[i] + best[i - 2], best[i - 1]);
	}
	std::cout << best[max];
}