#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <map>

#define in std::cin
#define out std::cout
#define endl std::endl
#define MAXE(a, b) a = std::max(a, b)
#define MINE(a, b) a = std::min(a, b)
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

SS strs;
std::map<S, int> m;
S str;

int main() {
	int n;
	in >> n;
	for(int i = 0; i < n; i++) {
		in >> str;
		if(strs.find(str) != strs.end()) {
			out << str << ++m[str] << endl;
		}else {
			strs.insert(str);
			m.insert(std::make_pair(str, 0));
			out << "OK" << endl;
		}
	}
}