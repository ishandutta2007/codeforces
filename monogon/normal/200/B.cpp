#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iomanip>

#define in std::cin
#define out std::cout
#define end std::endl
#define MAXE(a, b) a = std::max(a, b)
#define MINE(a, b) a = std::min(a, b)
#define VI std::vector<int>
#define VS std::vector<std::string>
#define PII std::pair<int, int>
#define SI std::set<int>
#define VII std::vector<int>::iterator
#define VSI std::vector<std::string>::iterator
#define SII std::set<int>::iterator

int n;
int a;
int tot;

int main() {
	in >> n;
	for(int i = 0; i < n; i++) {
		in >> a;
		tot += a;
	}
	out << std::fixed;
	out << std::setprecision(6);
	out << 1.0 * tot / n;
}