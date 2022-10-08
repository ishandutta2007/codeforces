#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

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

int n, k;
int a[2000];

int main() {
	in >> n >> k;
	for(int i = 0; i < n; i++) {
		in >> a[i];
	}
	std::sort(a, a + n);
	int i;
	for(i = 0; i < n && a[i] <= 5 - k; i++);
	out << i / 3;
}