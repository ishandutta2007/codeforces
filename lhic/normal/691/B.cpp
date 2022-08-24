#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

string s1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string s2 = "0d0b0000000000oqp0000vwx00A000000HI000M0O0000TUVWXY0";

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < (int)s.size(); ++i) {
		char x = s[i];
		char y = '1';
		for (int i = 0; i < (int)s1.size(); ++i)
			if (s1[i] == x)
				y = s2[i];
		assert(y != '1');
		if (s[s.size() - i - 1] != y) {
			cout << "NIE\n";
			return 0;
		}
	}
	cout << "TAK\n";
	return 0;
}