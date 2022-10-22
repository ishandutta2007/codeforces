#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

typedef long double ld;

const int Maxn = 2005;

int n, t;
ld p;
ld dp[Maxn][Maxn];

int main()
{
	cin >> n >> p >> t;
	for (int j = 0; j <= n; j++)
		dp[0][j] = j;
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j < n; j++)
			dp[i][j] = p * dp[i - 1][j + 1] + (1.0l - p) * dp[i - 1][j];
		dp[i][n] = n;
	}
	cout << fixed << setprecision(9) << dp[t][0] << endl;
	return 0;
}