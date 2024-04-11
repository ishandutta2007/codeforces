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
	string s, t, tmp;
	cin >> s;
	cin >> tmp;
	reverse(tmp.begin(), tmp.end());
	s += tmp;
	cin >> t;
	cin >> tmp;
	reverse(tmp.begin(), tmp.end());
	t += tmp;
	string s2, t2;
	for (int i = 0; i < (int)s.size(); ++i)
		if (s[i] != 'X')
			s2 += s[i];
	for (int i = 0; i < (int)t.size(); ++i)
		if (t[i] != 'X')
			t2 += t[i];
	s = s2;
	t = t2;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == 'A') {
			rotate(s.begin(), s.begin() + i, s.end());
			break;
		}
	}
	for (int i = 0; i < (int)t.size(); ++i) {
		if (t[i] == 'A') {
			rotate(t.begin(), t.begin() + i, t.end());
			break;
		}
	}
	if (s == t) {
		cout << "YES\n";
	}
	else
		cout << "NO\n";
	return 0;
}