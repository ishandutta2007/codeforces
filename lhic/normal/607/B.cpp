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
typedef double ld;

using namespace std;


int dp[1000][1000];
int a[1000];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i; j < n; ++j) {
			if (i == j) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = j - i + 1;
			for (int k = i; k < j; ++k)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
			if (a[i] == a[j]) {
				if (j == i + 1)
					dp[i][j] = 1;
				else
					dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
			}
		}
	}
	cout << dp[0][n - 1] << "\n";
	return 0;
}