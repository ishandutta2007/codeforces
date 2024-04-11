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

int n;
char s[120000];
int dp[3][3];

int main() {
	scanf("%d", &n);
	scanf(" %s", s);
	for (int i = 0; i <= 2; ++i)
		for (int j = 0; j < 2; ++j)
			dp[i][j] = 0;
	for (int i = 0; i < n; ++i) {
		int x = 0;
		if (s[i] == '1')
			x = 1;
		dp[2][x] = max({dp[2][x], dp[1][x] + 1, dp[2][x ^ 1] + 1});
		dp[1][x] = max({dp[1][x], dp[0][x] + 1, dp[1][x ^ 1] + 1});
		dp[0][x] = max(dp[0][x], dp[0][x ^ 1] + 1);
	}
	int mx = 0;
	for (int i = 0; i <= 2; ++i)
		for (int j = 0; j < 2; ++j)
			mx = max(mx, dp[i][j]);
	cout << mx << "\n";
	return 0;
}