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

const int MAXN = 210000;

char s1[MAXN];
char s2[MAXN];

void ss(char *s, int l, int r) {
	int n = r - l;
	if (n % 2 == 1)
		return;
	int m = (l + r) >> 1;
	ss(s, l, m);
	ss(s, m, r);
	int fl = 0;
	for (int i = 0; i < m - l; ++i) {
		if (s[i + l] > s[i + m]) {
			fl = 1;
			break;
		}
		if (s[i + l] < s[i + m]) {
			fl = -1;
			break;
		}
	}
	if (fl == 1) {
		for (int i = 0; i < m - l; ++i)
			swap(s[i + l], s[i + m]);
	}
}

int main() {
	scanf(" %s", s1);
	scanf(" %s", s2);
	int n = strlen(s1);
	ss(s1, 0, n);
	ss(s2, 0, n);
	int fl = 0;
	for (int i = 0; i < n; ++i)
		if (s1[i] != s2[i])
			fl = 1;
	if (fl)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}