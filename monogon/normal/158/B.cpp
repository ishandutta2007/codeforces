
#include <iostream>

int N;
int a;
int tot[5];
int sum = 0;

int main() {
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> a;
		tot[a]++;
	}
	sum = tot[4] + tot[3] + tot[2] / 2;
	if(tot[2] % 2) sum++;
	tot[1] -= tot[3] + 2 * (tot[2] % 2);
	if(tot[1] > 0) sum += tot[1] / 4 + (tot[1] % 4 > 0);
	std::cout << sum << std::endl;
}