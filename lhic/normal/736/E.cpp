#pragma GCC optimize "-O3"
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

int m, n;
int a[4000];
int c[4000][4000];
set<pair<int, int> > ss;
int en[4000];
char buf[4000];

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	int sum = m * (m - 1);
	int now = 0;
	for (int i = 0; i < n; ++i) {
		now += a[i];
		if (now > (i + 1) * i + 2 * (i + 1) * (m - (i + 1))) {
			cout << "no\n";
			return 0;
		}
		sum -= a[i];
	}
	if (m == n) {
		if (sum != 0) {
			cout << "no\n";
			return 0;
		}
	}
	else {
		int d = sum / (m - n);
		int k = sum % (m - n);
		for (int i = n; i < n + k; ++i)
			a[i] = d + 1;
		for (int i = n + k; i < m; ++i)
			a[i] = d;
		if (a[n - 1] < a[n]) {
			cout << "no\n";
			return 0;
		}
	}
	for (int i = 0; i < m; ++i)
		ss.insert(make_pair(-a[i], i));
	while (!ss.empty()) {
		int x = ss.begin()->second;
		ss.erase(ss.begin());
		en[x] = 1;
		int hv = 0;
		for (int i = 0; i < m; ++i)
			if (!en[i])
				c[x][i] = 2, c[i][x] = 0, hv += 2;
		hv -= a[x];
		set<pair<int, int> > tmp = ss;
		while (hv) {
			int y = tmp.begin()->second;
			tmp.erase(tmp.begin());
			ss.erase(make_pair(-a[y], y));
			--c[x][y];
			++c[y][x];
			--hv;
			--a[y];
			ss.insert(make_pair(-a[y], y));
			if (c[y][x] != 2)
				tmp.insert(make_pair(-a[y], y));
		}
	}
	printf("yes\n");
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == j)
				buf[j] = 'X';
			else if (c[i][j] == 2)
				buf[j] = 'W';
			else if (c[i][j] == 1)
				buf[j] = 'D';
			else
				buf[j] = 'L';
		}
		printf("%s\n", buf);
	}
	return 0;
}