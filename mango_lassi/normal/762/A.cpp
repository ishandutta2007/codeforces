#include <iostream>
#include <vector>
#include <set>

struct Pair {
	long long val;
	int amount;

	Pair(long long v, int a) {
		val = v;
		amount = a;
	}
};

Pair mp (long long v, int a) {
	Pair p (v, a);
	return p;
}

struct Div {
	long long val;
	std::vector<int> amounts;
	
	Div() {
		val = 1;
		std::vector<int> vec;
		amounts = vec;
	}

	Div(Div& oth, long long inc, int add) {
		val = oth.val * inc;
		std::vector<int> vec;
		amounts = vec;
		for (int i = 0; i < (int)oth.amounts.size(); ++i) {
			amounts.push_back(oth.amounts[i]);
		}
		++amounts[add];
	}

	bool operator< (const Div& oth) const {
		return val < oth.val;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	long long n, k;
	std::cin >> n >> k;
	std::vector<Pair> factors;
	for (long long i = 2; i * i <= n; ++i) {
		int a = 0;
		while(n % i == 0) {
			++a;
			n /= i;
		}
		if (a) {
			Pair p (i, a);
			factors.push_back(p);
		}
	}
	if (n != 1) {
		factors.push_back(mp(n, 1));
	}
	if (k == 1) {
		std::cout << "1\n";
	} else {
		--k;
		Div empty;
		for (int i = 0; i < (int)factors.size(); ++i) {
			empty.amounts.push_back(0);
		}
		std::set<Div> divs;
		for (int i = 0; i < (int)factors.size(); ++i) {
			Div d (empty, factors[i].val, i);
			divs.insert(d);
		}
		while(! divs.empty()) {
			auto it = divs.lower_bound(empty);
			Div d = *it;
			divs.erase(it);
			int max = 0;
			for (int i = 0; i < (int)d.amounts.size(); ++i) {
				if (d.amounts[i]) {
					max = i;
				}
			}
			for (int i = 0; i <= max; ++i) {
				if (d.amounts[i] < factors[i].amount) {
					Div nw (d, factors[i].val, i);
					divs.insert(nw);
				}
			}
			--k;
			if (k == 0) {
				std::cout << d.val << "\n";
				break;
			}
		}
		if (k > 0) {
			std::cout << "-1\n";
		}
	}
	// Case 1: Only one prime number in divisors:
	//	k-th divisor is prime ^ (k-1), or if amount of prime avaiable is less than k-1, -1. 
	// Case 2: n prime numbers
	// 	we push into a set the candinates, which are
	//	single copy of each prime at the very start.
	//	
	//	after we remove the nth prime, we add nth prime * 1st prime, nth prime * 2nd prime, ..., nth prime * nth prime.
	//	after we remove second element, we add: 
	//	
}