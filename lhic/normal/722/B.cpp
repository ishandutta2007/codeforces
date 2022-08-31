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

int n;
int p[12000];

int gl(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
		return 1;
	else
		return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	string s;
	getline(cin, s);
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		int cnt = 0;
		for (int j = 0; j < (int)s.size(); ++j)
			if (gl(s[j]))
				++cnt;
		if (cnt != p[i]) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	return 0;
}