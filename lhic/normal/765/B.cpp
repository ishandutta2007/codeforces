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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

string s;


int main() {
	cin >> s;
	char cur = 'a';
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] > cur) {
			cout << "NO\n";
			return 0;
		}
		else if (s[i] == cur) {
			++cur;
		}
	}
	cout << "YES\n";
	return 0;
}