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

int n;
int a[10][10];

int main() {
	in >> n;
	for(int i = 0; i < n; i++) {
		a[0][i] = 1;
		a[i][0] = 1;
	}
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < n; j++) {
			a[i][j] = a[i - 1][j] + a[i][j - 1];
		}
	}
	out << a[n - 1][n - 1];
}