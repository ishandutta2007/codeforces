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
typedef double ld;

using namespace std;

string s, a, b;


int check(string s) {
	if (s.empty())
		return 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (!isdigit(s[i]))
			return 0;
	}
	if (s[0] == '0' && (int)s.size() > 1)
		return 0;
	return 1;
}


int main() {
	cin >> s;
	string buf = "";
	s += ";";
	int fla = 0, flb = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] != ',' && s[i] != ';')
			buf += s[i];
		else {
			if (check(buf)) {
				if (!fla)
					a += buf;
				else
					a += ",", a += buf;
				fla = 1;
			}
			else {
				if (!flb)
					b += buf;
				else
					b += ",", b += buf;
				flb = 1;
			}
			buf = "";
		}
	}
	if (fla)
		cout << '"' << a << '"' << "\n";
	else
		cout << "-\n";
	if (flb)
		cout << '"' << b << '"' << "\n";
	else
		cout << "-\n";
	return 0;
}