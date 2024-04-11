#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cmath>

#define in std::cin
#define out std::cout
#define endl std::endl
#define MAX(a, b) std::max(a, b)
#define MAX3(a, b, c) std::max(a, std::max(b, c))
#define MIN(a, b) std::min(a, b)
#define MIN3(a, b, c) std::min(a, std::min(b, c))
#define MAXE(a, b) a = std::max(a, b)
#define MINE(a, b) a = std::min(a, b)
#define GETBIT(a, n) ((a >> n) & 1)
#define BITCOUNT(a) __builtin_popcount(a)
#define S std::string
#define Ss std::stringstream
#define VI std::vector<int>
#define VS std::vector<std::string>
#define MP(a, b) std::make_pair(a, b)
#define PII std::pair<int, int>
#define PSI std::pair<std::string, int>
#define PIS std::pair<int, std::string>
#define PSS std::pair<std::string, std::string>
#define SI std::set<int>
#define SS std::set<std::string>
#define SPII std::set<std::pair<int, int> >
#define SPSI std::set<std::pair<std::string, int> >
#define SPIS std::set<std::pair<int, std::string> >
#define SPSS std::set<std::pair<std::string, std::string> >
#define MSI std::multiset<int>
#define MSS std::multiset<std::string>
#define VII std::vector<int>::iterator
#define VSI std::vector<std::string>::iterator
#define SII std::set<int>::iterator
#define SPIII std::set<std::pair<int, int> >::iterator
#define SPSII std::set<std::pair<std::string, int> >::iterator
#define SPISI std::set<std::pair<int, std::string> >::iterator
#define SPSSI std::set<std::pair<std::string, std::string> >::iterator
#define MSIII std::multiset<int>::iterator
#define MSSI std::multiset<std::string>::iterator
#define MAPII std::map<int, int>
#define MAPSS std::map<std::string, std::string>
#define MAPIS std::map<int, std::string>
#define MAPSI std::map<std::string, int>

int m, s;

S largest(int len, int sum) {
	Ss ss;
	while(sum > 9) {
		ss << 9;
		sum -= 9;
	}
	if(sum > 0)
		ss << sum;
	while(ss.tellp() < len)
		ss << 0;
	return ss.str();
}

int main() {
	in >> m >> s;
	if(s == 0 && m == 1) {
		out << "0 0";
		return 0;
	}
	if(s == 0 || s > 9 * m) {
		out << "-1 -1";
		return 0;
	}
	S g = largest(m, s);
	S l = largest(m, s - 1);
	std::reverse(l.begin(), l.end());
	l[0]++;
	out << l << " " << g;
}