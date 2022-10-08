#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

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

std::string arr[1000];
int n;

int main() {
	in >> n;
	bool open = false;
	for(int i = 0; i < n; i++) {
		in >> arr[i];
		if(!open && arr[i][0] == 'O' && arr[i][1] == 'O') {
			arr[i][0] = '+';
			arr[i][1] = '+';
			open = true;
		}
		if(!open && arr[i][3] == 'O' && arr[i][4] == 'O') {
			arr[i][3] = '+';
			arr[i][4] = '+';
			open = true;
		}
	}
	if(open) {
		out << "YES" << end;
		for(int i = 0; i < n; i++)
			out << arr[i] << end;
	}
	else out << "NO";
}