#include <iostream>
#include <algorithm>
#include <iomanip>
#include <set>

#define in std::cin
#define out std::cout
#define MAXE(a, b) a = std::max(a, b);

int n, l;
int num;
std::set<int> a;

int main() {
	in >> n >> l;
	for(int i = 0; i < n; i++) {
		in >> num;
		a.insert(num);
	}
	std::set<int>::iterator it = a.begin();
	int last = *it;
	int first = *it;
	double max = 0;
	for(it++; it != a.end(); it++) {
		MAXE(max, (0.5) * (*it - last));
		last = *it;
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(1);
	std::cout << std::max(max, 1.0 * std::max(first, l - last));
}