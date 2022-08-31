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

const int INF = 100000;

int dp[40][40][60];

int main() {
	for (int l = 2; l <= 60; ++l) {
		for (int i = 1; i <= min(l, 30); ++i) {
			if (l - i > 30)
				continue;
			for (int k = 0; k <= 50; ++k) {
				if (l - i < i) {
					dp[i][l - i][k] = dp[l - i][i][k];
					continue;
				}
				int j = l - i;
				if (k == 0 || k == i * j) {
					dp[i][j][k] = 0;
					continue;
				}
				if (k > i * j) {
					dp[i][j][k] = INF;
					continue;
				}
				dp[i][j][k] = INF;
				for (int d = 1; d < i; ++d)
					for (int g = 0; g <= k; ++g)
						dp[i][j][k] = min(dp[i][j][k], dp[d][j][g] + dp[i - d][j][k - g] + j * j);
				for (int d = 1; d < j; ++d)
					for (int g = 0; g <= k; ++g)
						dp[i][j][k] = min(dp[i][j][k], dp[i][d][g] + dp[i][j - d][k - g] + i * i);
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int n, m, k;
		cin >> n >> m >> k;
		cout << dp[n][m][k] << "\n";
	}
	return 0;
}