
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define in std::cin
#define out std::cout
//#define end std::endl
#define MAXE(a, b) a = std::max(a, b)
#define MINE(a, b) a = std::min(a, b)
#define VI std::vector<int>
#define VS std::vector<std::string>
#define PII std::pair<int, int>
#define SI std::set<int>
#define MSI std::multiset<long long>
#define VII std::vector<int>::iterator
#define VSI std::vector<std::string>::iterator
#define SII std::set<int>::iterator
#define MSII std::multiset<long long>::iterator

long long n, a, p1, p2;
MSI s, s2, s3;

int main() {
	in >> n;
	for(long long i = 0; i < n; i++) {
		in >> a;
		s.insert(a);
	}
	for(long long i = 0; i < n - 1; i++) {
		in >> a;
		s2.insert(a);
	}
	for(long long i = 0; i < n - 2; i++) {
		in >> a;
		s3.insert(a);
	}
	p1 = *(--s.end());
	MSII i2 = s2.begin();
	for(MSII i = s.begin(); i2 != s2.end(); i++) {
		if(*i != *i2) {
			p1 = *i;
			break;
		}
		i2++;
	}
	p2 = *(--s2.end());
	i2 = s3.begin();
	for(MSII i = s2.begin(); i2 != s3.end(); i++) {
		if(*i != *i2) {
			p2 = *i;
			break;
		}
		i2++;
	}
	out << p1 << std::endl << p2;
}