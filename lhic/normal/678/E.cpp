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

ld p[20][20];
ld dp[(1 << 17) + 10][20];
int n;


int main() {
	cin >> n;
	if (n == 1) {
		cout << 1 << "\n";
		return 0;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> p[i][j];
	--n;
	for (int i = 1; i < (1 << n); ++i) {
		for (int st = 1; st <= n; ++st) {
			if (!((i >> (st - 1)) & 1))
				continue;
			if (__builtin_popcount(i) == 1) { 
				dp[i][st] = p[0][st];
				continue;
			}
			for (int j = 1; j <= n; ++j) {
				if (j == st || !((i >> (j - 1)) & 1))
					continue;
				dp[i][st] = max(dp[i][st], p[st][j] * dp[i ^ (1 << (j - 1))][st] + p[j][st] * dp[i ^ (1 << (st - 1))][j]);
			}
		}
	}
	ld mx = 0;
	for (int i = 1; i <= n; ++i)
		mx = max(mx, dp[(1 << n) - 1][i]);
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << mx << "\n";
	return 0;
}