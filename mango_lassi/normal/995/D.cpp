#include <iostream>
#include <iomanip>

/*
With one bit unset: 1/2 (first + second)
With two bits unset: 1/2 (1/2 (first + second) + 1/2(third + fourth))

If they always wanted to set the same bit, answer would be sum of all / 2^n
*/

const int N = 1<<18;
int val[N];

int main() {
	int n, r;
	std::cin >> n >> r;
	long long sum = 0;
	int cou = 1<<n;
	for (int i = 0; i < cou; ++i) {
		std::cin >> val[i];
		sum += val[i];
	}
	for (int i = 0; i < r; ++i) {
		std::cout << std::fixed << std::setprecision(20) << (long double)sum / cou << '\n';
		int a, v;
		std::cin >> a >> v;
		sum += v - val[a];
		val[a] = v;
	}
	std::cout << std::fixed << std::setprecision(20) << (long double)sum / cou << '\n';
}