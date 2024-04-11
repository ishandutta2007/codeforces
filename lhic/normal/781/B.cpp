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

string s, t;
string s1[1200];
string s2[1200];
string ans[1200];
int en[1200];
set<string> mm;
int n;

void add(string s) {
	if (mm.count(s)) {
		cout << "NO\n";
		exit(0);
	}
	mm.insert(s);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s >> t;
		s1[i] = string(1, s[0]) + string(1, s[1]) + string(1, s[2]);
		s2[i] = string(1, s[0]) + string(1, s[1]) + string(1, t[0]);
	}
	for (int i = 0; i < n; ++i) {
		int fl = 0;
		for (int j = 0; j < n; ++j) {
			if (j == i)
				continue;
			if (s1[i] == s1[j]) {
				fl = 1;
				break;
			}
		}
		if (fl) {
			en[i] = 1;
			ans[i] = s2[i];
			add(s2[i]);
		}
	}
	int ch = 1;
	while (ch) {
		ch = 0;
		for (int i = 0; i < n; ++i) {
			if (en[i])
				continue;
			if (mm.count(s1[i])) {
				en[i] = 1;
				add(s2[i]);
				ans[i] = s2[i];
				ch = 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!en[i]) {
			add(s1[i]);
			ans[i] = s1[i];
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i)
		cout << ans[i] << "\n";
	return 0;
}