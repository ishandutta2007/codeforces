#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int lim = 4005;
const int inf = 1e+9 + 7;

unsigned int dp[lim][lim];

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/

	unsigned int i, j, n, res = 0;
	cin >> n;
	for (j = 1; j < lim; ++j)
		for (i = j; i < lim; ++i)
			dp[i][j] = (i == j ? 1 : int(((ll)(dp[i - 1][j]) * (ll)j + (ll)dp[i - 1][j - 1]) % inf));
	for (i = 1; i <= n; ++i)
		res = int(((ll)(res) + (ll)(dp[n][i]) * (ll)(i)) % inf);
	cout << res;
	return 0;
}