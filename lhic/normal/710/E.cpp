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

const int MX = 12e6;
ll dp[MX];
int n;
ll x, y;

int main() {
	cin >> n >> x >> y;
	for (int i = 0; i < MX; ++i)
		dp[i] = i * x;
	for (int it = 0; it < 24; ++it) {
		for (int i = 0; i * 2 < MX; ++i)
			dp[i * 2] = min(dp[i * 2], dp[i] + y);
		for (int i = 0; i < MX - 1; ++i)
			if (dp[i + 1] > dp[i] + x)
				dp[i + 1] = dp[i] + x;
		for (int i = MX - 1; i > 0; --i)
			if (dp[i - 1] > dp[i] + x)
				dp[i - 1] = dp[i] + x;
	}
	cout << dp[n] << "\n";
	return 0;
}