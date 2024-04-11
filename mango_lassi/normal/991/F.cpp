#include <iostream>
#include <string>
#include <vector>

const long long inf = 1e10;

long long pow(long long a, long long b) {
	long long res = 1;
	for (long long i = 0; i < b; ++i) {
		res *= a;
		if (res >= inf) return inf;
	}
	return res;
}
long long mult(long long a, long long b) {
	long double res = (long double)a * b;
	if (res >= inf) return inf;
	return a * b;
}
std::vector<long long> getOrder(long long i) {
	if (i == 0) {
		return {10, 10, 10, 10};
	} else if (i <= 4) {
		std::vector<long long> res (4, 10);
		res[i - 1] = 100;
		return res;
	} else if (i <= 8) {
		std::vector<long long> res (4, 10);
		res[i - 5] = 1000;
		return res;
	} else if (i <= 14) {
		if (i == 9) return {100, 100, 10, 10};
		if (i == 10) return {100, 10, 100, 10};
		if (i == 11) return {100, 10, 10, 100};
		if (i == 12) return {10, 100, 100, 10};
		if (i == 13) return {10, 100, 10, 100};
		if (i == 14) return {10, 10, 100, 100};
	} else {
		return {-1};
	}
}

int main() {
	long long n;
	std::cin >> n;
	if (n == (long long)1e10) {
		std::cout << "10^10\n";
	} else {
		std::string best = std::to_string(n);
		std::string empty = "";

		// Case 1: a^b * c^d * e  (1e5 possibilities)
		// Case 2: a^b * c^d + e  (1e5 possibilities)
		// Case 3: a^b + c^d * e
		for (long long a = 2; a < 10; ++a) {
			for (long long b = 2; b < 10; ++b) {
				for (long long c = 2; c < 10; ++c) {
					for (long long d = 2; d < 10; ++d) {
						long long base = mult(pow(a, b), pow(c, d));
						if (n % base == 0) {
							long long e = n / base;
							if (e > 0 && e < 10) {
								std::string offer = empty + std::to_string(a) + "^" + std::to_string(b) + "*" + std::to_string(c) + "^" + std::to_string(d) + "*" + std::to_string(e);
								if (offer.size() < best.size()) best = offer;
								a = 10;
								b = 10;
								c = 10;
								d = 10;
							}
						} else {
							long long e = n - base;
							if (e > 0 && e < 10) {
								std::string offer = empty + std::to_string(a) + "^" + std::to_string(b) + "*" + std::to_string(c) + "^" + std::to_string(d) + "+" + std::to_string(e);
								if (offer.size() < best.size()) best = offer;
								a = 10;
								b = 10;
								c = 10;
								d = 10;

							}
						}
						long long base1 = pow(a, b);
						long long base2 = pow(c, d);
						if ((n - base1) % base2 == 0) {
							long long rem = n - base1;
							long long e = rem / base2;
							if (0 < e && e < 10) {
								std::string offer = empty + std::to_string(a) + "^" + std::to_string(b) + "+" + std::to_string(c) + "^" + std::to_string(d) + "*" + std::to_string(e);
								if (offer.size() < best.size()) best = offer;
								a = 10;
								b = 10;
								c = 10;
								d = 10;
							}
						}
					}
				}
			}
		}

		// Case 4: a^b * c^d      (1e6 possibilities)
		// Case 5: a^b + c^d      (1e6 possibilities)
		// Case 6: a   * b^c + d  (1e6 possibilities)
		for (long long i = 0; ; ++i) {
			std::vector<long long> maxes = getOrder(i);
			if (maxes[0] == -1) break;
			for (long long a = 2; a < maxes[0]; ++a) {
				for (long long b = 2; b < maxes[1]; ++b) {
					for (long long c = 2; c < maxes[2]; ++c) {
						for (long long d = 2; d < maxes[3]; ++d) {
							long long base = mult(pow(a, b), pow(c, d));
							if (base == n) {
								std::string offer = empty + std::to_string(a) + "^" + std::to_string(b) + "*" + std::to_string(c) + "^" + std::to_string(d);
								if(offer.size() < best.size()) best = offer;
								i = -1;
								a = maxes[0];
								b = maxes[1];
								c = maxes[2];
								d = maxes[3];
							}
							long long base1 = pow(a, b);
							long long base2 = pow(c, d);
							if (n == base1 + base2) {
								std::string offer = empty + std::to_string(a) + "^" + std::to_string(b) + "+" + std::to_string(c) + "^" + std::to_string(d);
								if(offer.size() < best.size()) best = offer;
								i = -1;
								a = maxes[0];
								b = maxes[1];
								c = maxes[2];
								d = maxes[3];
							}
						}
					}
				}
			}
			if (i == -1) break;
			for (long long a = 2; a < maxes[0]; ++a) {
				for (long long b = 2; b < maxes[1]; ++b) {
					for (long long c = 2; c < maxes[2]; ++c) {
						for (long long d = 0; d < maxes[3]; ++d) {
							long long base = mult(a, pow(b, c)) + d;
							if (base == n) {
								std::string offer = empty + std::to_string(a) + "*" + std::to_string(b) + "^" + std::to_string(c) + "+" + std::to_string(d);
								if(offer.size() < best.size()) best = offer;
								i = -1;
								a = maxes[0];
								b = maxes[1];
								c = maxes[2];
								d = maxes[3];
							}
						}
					}
				}
			}
			if (i == -1) break;
		}
		
		// Case 7: a   * b^c      (loop c)
		// Case 8:       b^c + d  (loop c)
		// Case 9:       b^c      (loop c)
		for (long long c = 2; c < 40; ++c) {
			for (long long b = 2;; ++b) {
				long long pb = pow(b, c);
				if (pb == inf) break;
				if (n % pb == 0) {
					long long a = n / pb;
					std::string offer = empty + std::to_string(a) + "*" + std::to_string(b) + "^" + std::to_string(c);
					if(offer.size() < best.size()) best = offer;
				} else {
					long long d = n - pb;
					if (d > 0) {
						std::string offer = empty + std::to_string(b) + "^" + std::to_string(c) + "+" + std::to_string(d);
						if(offer.size() < best.size()) best = offer;
					}
				}
				if (n == pb) {
					std::string offer = empty + std::to_string(b) + "^" + std::to_string(c);
					if(offer.size() < best.size()) best = offer;
				}
			}
		}

		std::cout << best << '\n';
	}
}