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

char s[400][400];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf(" %s", s[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (i == j || i + j == n - 1) {
				if (s[i][j] != s[0][0]) {
					cout << "NO\n";
					return 0;
				}
			}
			else {
				if (s[i][j] != s[0][1] || s[i][j] == s[0][0]) {
					cout << "NO\n";
					return 0;
				}
			}
		}
	cout << "YES\n";
	return 0;
}