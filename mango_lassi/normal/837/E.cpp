#include <iostream>
#include <utility>
#include <vector>

long long gcd(long long a, long long b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long solve(long long x, long long y, std::vector<std::pair<long long, int>> factor) {
	/*
	std::cout << x << ' ' << y << '\n';
	for (int j = 0; j < factor.size(); ++j) {
		std::cout << "( " << factor[j].first << ' ' << factor[j].second << " ),";
	}
	std::cout << '\n';
	*/
	if (x == 1) return y;
	long long min = y % factor[0].first;
	for (int j = 1; j < factor.size(); ++j) {
		long long val = y % factor[j].first;
		if (val < min) {
			min = val;
		}
	}
	y -= min;
	long long res = gcd(x, y);
	x /= res;
	y /= res;
	for (int i = 0; i < factor.size(); ++i) {
		long long prime = factor[i].first;
		int count = 0;
		while(res % prime == 0) {
			res /= prime;
			++count;
		}
		if (factor[i].second == count) {
			factor[i] = factor[factor.size()-1];
			factor.pop_back();
			--i;
		} else {
			factor[i] = {prime, factor[i].second - count};
		}
	}
	return solve(x, y, factor) + min;
}

int main() {
	long long x, y;
	std::cin >> x >> y;
	long long div = gcd(x, y);
	x /= div;
	y /= div;

	std::vector<std::pair<long long, int>> factor;
	int max = 1e6;
	long long tmp = x;
	for (int j = 2; j <= max; ++j) {
		int count = 0;
		while(tmp % j == 0) {
			++count;
			tmp /= j;
		}
		if (count > 0) {
			factor.push_back({j, count});
		}
	}
	if (tmp != 1) factor.push_back({tmp, 1});
	std::cout << solve(x, y, factor) << '\n';
}