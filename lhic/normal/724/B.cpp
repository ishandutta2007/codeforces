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

int n, m;
int a[30][30];

int gd(int i) {
	for (int j = 0; j < m; ++j)
		if (a[i][j] != j)
			return 0;
	return 1;
}

int check(int l, int x, int y) {
	swap(a[l][x], a[l][y]);
	if (gd(l)) {
		swap(a[l][x], a[l][y]);
		return 1;
	}
	for (int i = 0; i < m; ++i)
		for (int j = i + 1; j < m; ++j) {
			swap(a[l][i], a[l][j]);
			if (gd(l)) {
				swap(a[l][i], a[l][j]);
				swap(a[l][x], a[l][y]);
				return 1;
			}
			swap(a[l][i], a[l][j]);
		}
	swap(a[l][x], a[l][y]);
	for (int i = 0; i < m; ++i)
		for (int j = i + 1; j < m; ++j) {
			swap(a[l][i], a[l][j]);
			swap(a[l][x], a[l][y]);
			if (gd(l)) {
				swap(a[l][x], a[l][y]);
				swap(a[l][i], a[l][j]);
				return 1;
			}
			swap(a[l][x], a[l][y]);
			swap(a[l][i], a[l][j]);
		}
	return 0;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j], --a[i][j];
	for (int i = 0; i < m; ++i) {
		for (int j = i; j < m; ++j) {
			int fl = 0;
			for (int k = 0; k < n; ++k)
				if (!check(k, i, j)) {
					fl = 1;
					break;
				}
			if (!fl) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}