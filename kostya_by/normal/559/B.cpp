#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

string a, b;

string rec_min(const string &s) {
	if (s.size() % 2) {
		return s;
	}

	string a, b;
	for (int i = 0; i < s.size() / 2; i++) {
		a += s[i];
		b += s[i + s.size() / 2];
	}

	a = rec_min(a);
	b = rec_min(b);

	string ab = a + b;
	string ba = b + a;

	if (ab < ba) {
		return ab;
	} 
	return ba;
}

void solve() {
	cin >> a >> b;
	a = rec_min(a);
	b = rec_min(b);

	if (a == b) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}