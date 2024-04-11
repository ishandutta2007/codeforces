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

int n;
int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < 1000; ++i)
		s += '.';
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int d = j - i;
			if (s[i] == '*' && s[j] == '*' && s[j + d] == '*' && s[j + d + d] == '*' && s[j + d + d + d] == '*') {
				cout << "yes";
				return 0;
			}
		}
	}
	cout << "no";
	return 0;
}