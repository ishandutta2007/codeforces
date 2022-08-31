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

const int MX = 100;

int pr[4010];
int dp[2010][MX + 5][MX + 5];
int n;
int a[4010];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	pr[0] = 0;
	for (int i = 0; i < n; ++i)
		pr[i + 1] = pr[i] + a[i];
	int n2 = n / 2;
	for (int i = n2; i >= 0; --i) {
		for (int d = 0; d < MX; ++d) {
			for (int k = 1; k < MX; ++k) {
				if (d > k)
					continue;
				if (2 * i + d + k > n)
					continue;
				if (2 * i + d + k + k > n) {
					dp[i][d][k] = pr[i + k] - pr[i];
				}
				else {
					if (2 * i + d + k + k + 1 > n)
						dp[i][d][k] = pr[i + k] - pr[i] - (pr[n - i - d] - pr[n - i - d - k]);
					else
						dp[i][d][k] = pr[i + k] - pr[i] + min(dp[i + k][d][k] - (pr[n - i - d] - pr[n - i - d - k]), dp[i + k][d + 1][k + 1] - (pr[n - i - d] - pr[n - i - d - k - 1]));
				}
				if (2 * i + d + k + 1 <= n) {
					if (2 * i + d + k + 1 + k + 1 > n) {
						dp[i][d][k] = max(dp[i][d][k], pr[i + k + 1] - pr[i]);
					}
					else {
						if (2 * i + d + k + 1 + k + 2 > n)
							dp[i][d][k] = max(dp[i][d][k], pr[i + k + 1] - pr[i] - (pr[n - i - d] - pr[n - i - d - k - 1]));
						else
							dp[i][d][k] = max(dp[i][d][k], pr[i + k + 1] - pr[i] + min(dp[i + k + 1][d][k + 1] - (pr[n - i - d] - pr[n - i - d - k - 1]), dp[i + k + 1][d + 1][k + 2] - (pr[n - i - d] - pr[n - i - d - k - 2])));
					}
				}
			}
		}
	}
	cout << dp[0][0][1] << "\n";
	return 0;
}