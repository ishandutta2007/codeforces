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

int n, m, b, MOD;
int dp[600][600];
int a[600];

int main() {
	cin >> n >> m >> b >> MOD;
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int ii = 0; ii < n; ++ii) {
		for (int i = 0; i <= m; ++i)
			for (int j = 0; j <= b; ++j) {
				if (i > 0 && j >= a[ii]) {
					dp[i][j] += dp[i - 1][j - a[ii]];
					if (dp[i][j] >= MOD)
						dp[i][j] -= MOD;
				}
			}
	}

	int sum = 0;
	for (int i = 0; i <= b; ++i) {
		sum += dp[m][i];
		if (sum >= MOD)
			sum -= MOD;
	}

	cout << sum % MOD;


	return 0;
}