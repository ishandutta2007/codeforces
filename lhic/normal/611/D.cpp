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

const int MAXN = 5100;
const int MOD = 1000000007;

int z[MAXN];
string s;
int n;
int dp[MAXN][MAXN];
bool cmp(int i, int j) {
	assert(j > i);
	int k = z[j - i];
	if (k >= j - i)
		return 0;
	if (j + k == n)
		return 0;
	return s[i + k] < s[j + k];
}

int main() {
	cin >> n;
	cin >> s;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == '0')
			continue;
		z[0] = 0;
		int l = 0;
		int r = 0;
		for (int j = i + 1; j < n; ++j) {
			int d = j - i;
			z[d] = 0;
			if (d < r)
				z[d] = min(r - d, z[d - l]);
			while (j + z[d] < n && s[i + z[d]] == s[j + z[d]])
				++z[d];
			if (d + z[d] > r)
				r = d + z[d], l = d;
		}
		dp[i][n + 1] = 0;
		for (int l = n; l >= 1; --l) {
			dp[i][l] = dp[i][l + 1];
			if (i + l >= n || i + l + l > n) {
				if (i + l == n)
					++dp[i][l];
			}
			else {
				if (s[i + l] == '0')
					continue;
				if (cmp(i, i + l))
					dp[i][l] = (dp[i][l] + dp[i + l][l]) % MOD;
				else
					dp[i][l] = (dp[i][l] + dp[i + l][l + 1]) % MOD;

			}
		}
	}
	cout << dp[0][1] % MOD << "\n";
	return 0;
}