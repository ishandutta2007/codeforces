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


int main() {
	string cf = "CODEFORCES";
	string s;
	cin >> s;
	for (int i = 0; i < (int)s.size(); ++i) {
		for (int j = i; j < (int)s.size(); ++j) {
			string buf = "";
			for (int ii = 0; ii < i; ++ii)
				buf += s[ii];
			for (int ii = j + 1; ii < (int)s.size(); ++ii)
				buf += s[ii];
			if (buf == cf) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}