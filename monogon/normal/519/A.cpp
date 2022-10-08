#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>

#define in std::cin
#define out std::cout
#define endl std::endl
#define MAX(a, b) std::max(a, b)
#define MAX(a, b, c) std::max(a, std::max(b, c))
#define MIN(a, b) std::min(a, b)
#define MIN(a, b, c) std::min(a, std::min(b, c))
#define MAXE(a, b) a = std::max(a, b)
#define MINE(a, b) a = std::min(a, b)
#define GETBIT(a, n) ((a >> n) & 1)
#define BITCOUNT(a) __builtin_popcount(a)
#define S std::string
#define Ss std::stringstream
#define VI std::vector<int>
#define VS std::vector<std::string>
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

S str;
int tot;

MAPII val;

int main() {
	val['.'] = 0;
	val['k'] = 0;
	val['q'] = 9;
	val['r'] = 5;
	val['b'] = 3;
	val['n'] = 3;
	val['p'] = 1;
	val['K'] = 0;
	val['Q'] = -9;
	val['R'] = -5;
	val['B'] = -3;
	val['N'] = -3;
	val['P'] = -1;
	for(int i = 0; i < 8; i++) {
		in >> str;
		for(int j = 0; j < 8; j++) {
			tot += val[str[j]];
		}
	}
	if(tot > 0) out << "Black";
	else if(tot < 0) out << "White";
	else out << "Draw";
}