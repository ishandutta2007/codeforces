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
const int MOD = 1e9 + 7;

int dp[77][1 << 20];
int en[1 << 20];
string s;
int n;

int main() {
	cin >> n;
	cin >> s;
	dp[0][0] = 1;
	ll ans = 0;
	ll now = 0;
	for (int i = 1; i <= 20; ++i)
		now += (1 << (i - 1)), en[now] = 1;
	for (int i = 0; i < n; ++i) {
		int now = 0;
		int ml = 1;
		int x = i + 1;
		dp[x][0] = 1;
		for (int j = i; j >= 0; --j) {
			now += (s[j] - '0') * ml;
			ml *= 2;
			ml = min(ml, 1000);
			if (now > 20)
				break;
			if (now == 0)
				continue;
			int y = j;
			for (int k = 0; k < (1 << 20); ++k) {
				dp[x][k | (1 << (now - 1))] += dp[y][k];
				if (dp[x][k | (1 << (now - 1))] >= MOD)
					dp[x][k | (1 << (now - 1))] -= MOD;
			}
		}
		for (int j = 1; j < (1 << 20); ++j) {
			if (en[j])
				ans = (ans + dp[x][j]) % MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}