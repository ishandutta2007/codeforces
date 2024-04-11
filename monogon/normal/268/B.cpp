#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

#define in std::cin
#define out std::cout
//#define end std::endl
//#define MAXE(a, b) a = std::max(a, b)
//#define MINE(a, b) a = std::min(a, b)
//#define VI std::vector<int>
//#define VS std::vector<std::string>
//#define PII std::pair<int, int>
//#define SI std::set<int>
//#define VII std::vector<int>::iterator
//#define VSI std::vector<std::string>::iterator
//#define SII std::set<int>::iterator

long long n;
long long a[2001];
long long b[2001];

int main() {
	in >> n;
	a[1] = 1;
	b[1] = 0;
	for(long long i = 2; i < n; i++) {
		a[i] = i - 1 + a[i - 1] + b[i - 1];
		b[i] = i - 1 + b[i - 1];
	}
	out << n * (n * n + 5) / 6;
}