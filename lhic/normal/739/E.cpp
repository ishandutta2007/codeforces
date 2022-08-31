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

int n, a, b;
int dp[1100][2100];
int p[2100];
int q[2100];

inline void upd(int &x, int y) {
	if (x < y)
		x = y;
}


int main() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		ld x;
		cin >> x;
		x *= 1000;
		p[i] = llround(x);
	}
	for (int i = 0; i < n; ++i) {
		ld x;
		cin >> x;
		x *= 1000;
		q[i] = llround(x);
	}
	if (a <= 1000) {
		for (int i = 0; i < n; ++i) {
			for (int j = min(a, i); j >= 0; --j)
				for (int k = min(b, i); k >= 0; --k) {
					upd(dp[j + 1][k], dp[j][k] + p[i] * 1000);
					upd(dp[j][k + 1], dp[j][k] + q[i] * 1000);
					upd(dp[j + 1][k + 1], dp[j][k] + p[i] * 1000 + q[i] * 1000 - q[i] * p[i]);
				}
		}
		cout << (ld)dp[a][b] / 1000000.0 << "\n";
	}
	else {
		for (int i = 0; i <= (n - a); ++i)
			for (int j = 0; j <= b; ++j)
				dp[i][j] = -1000000000;
		dp[0][0] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = min(n - a, i); j >= 0; --j)
				for (int k = min(b, i); k >= 0; --k) {
					upd(dp[j + 1][k], dp[j][k]);
					upd(dp[j][k + 1], dp[j][k] + p[i] * 1000 + q[i] * 1000 - q[i] * p[i]);
					upd(dp[j + 1][k + 1], dp[j][k] + q[i] * 1000);
					dp[j][k] += p[i] * 1000;
				}
		}
		cout << (ld)dp[n - a][b] / 1000000.0 << "\n";

	}
	return 0;
}