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

void ex() {
	cout << "NO\n";
	exit(0);
}

int main() {
	int n;
	cin >> n;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		string s;
		cin >> x >> s;
		if (s[0] == 'S') {
			cur += x;
			if (cur > 20000)
				ex();
		}
		else if (s[0] == 'N') {
			cur -= x;
			if (cur < 0)
				ex();
		}
		else if (s[0] == 'W') {
			if (cur == 0 || cur == 20000)
				ex();
		}
		else {
			if (cur == 0 || cur == 20000)
				ex();
		}
	}
	if (cur != 0)
		ex();
	cout << "YES\n";
	return 0;
}