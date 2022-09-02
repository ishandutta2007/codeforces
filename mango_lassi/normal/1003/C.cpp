#include <iostream>
#include <vector>
#include <iomanip>
typedef long long ll;

const int N = 1e6;
ll temps[N];

bool compAverage(ll sum_a, ll cou_a, ll sum_b, ll cou_b) {
	return sum_a * cou_b > sum_b * cou_a;
}

int main() {
	int n, k;
	std::cin >> n >> k;
	
	int j = 0;
	int pf = 0;
	ll sum = 0;
	ll best_sum = 0;
	ll best_len = 1;
	for (int i = 0; i < n; ++i) {
		std::cin >> temps[i];
	}
	for (int a = 0; a < n; ++a) {
		ll sum = 0;
		for (int b = a; b < n; ++b) {
			sum += temps[b];
			ll len = b-a+1;
			if (len >= k) {
				if (compAverage(sum, len, best_sum, best_len)) {
					best_sum = sum;
					best_len = len;
				}
			}
		}
	}
	std::cout << std::fixed << std::setprecision(20) << (long double)(best_sum) / best_len << '\n';
}