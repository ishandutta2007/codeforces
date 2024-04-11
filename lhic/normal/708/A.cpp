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
	int n = s.size();
	int fl = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'a')
			continue;
		fl = 1;
		for (int j = i; j < n; ++j) {
			if (s[j] == 'a')
				break;
			s[j] = s[j] - 1;
		}
		break;
	}
	if (!fl) {
		s[n - 1] = 'z';
	}
	cout << s << "\n";
	return 0;
}