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
string s;


int main() {
	cin >> s;
	for (int i = 1; i < (int)s.size(); ++i) {
		if (s[i] == s[i - 1]) {
			for (char j = 'a'; j <= 'z'; ++j) {
				if (j != s[i] && (i == (int)s.size() - 1 || j != s[i + 1])) {
					s[i] = j;
					break;
				}
			}
		}
	}
	cout << s << "\n";
	return 0;
}