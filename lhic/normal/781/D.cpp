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

const int LOG = 60;
bitset<501> a[LOG][501];
bitset<501> b[LOG][501];
const ll INF = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
int n, m;
bitset<501> ans;
bitset<501> ans2;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		--x, --y;
		if (t == 0)
			a[0][y][x] = 1;
		else
			b[0][y][x] = 1;
	}
	for (int it = 1; it < LOG; ++it) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (a[it - 1][i][j])
					b[it][i] |= b[it - 1][j];
				if (b[it - 1][i][j])
					a[it][i] |= a[it - 1][j];
			}
	}
	/*
	for (int i = 0; i < 5; ++i) {
		cerr << i << "\n";
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k)
				cerr << a[i][j][k] << " ";
			cerr << "\n";
		}
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k)
				cerr << b[i][j][k] << " ";
			cerr << "\n";
		}
	}*/
	ll now = 0;
	int cur = 0;
	ans[0] = 1;
	for (int i = LOG - 1; i >= 0; --i) {
		if (cur == 0) {
			for (int j = 0; j < n; ++j)
				ans2[j] = (ans & a[i][j]).any();
			for (int j = 0; j < n; ++j) {
				if (ans2[j]) {
					ans = ans2;
					now += (1ll << i);
					cur ^= 1;
					break;
				}
			}
		}
		else {
			for (int j = 0; j < n; ++j)
				ans2[j] = (ans & b[i][j]).any();
			for (int j = 0; j < n; ++j) {
				if (ans2[j]) {
					ans = ans2;
					now += (1ll << i);
					cur ^= 1;
					break;
				}
			}
		}
	}
	if (now > INF)
		cout << -1 << "\n";
	else
		cout << now << "\n";
	return 0;
}