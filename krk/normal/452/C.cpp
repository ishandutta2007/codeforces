#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;

const int Maxn = 1005;

int n, m;
ld dp[Maxn][Maxn];
ld res;

int main()
{
	scanf("%d %d", &n, &m);
	int my = m, oth = (n - 1) * m;
	dp[1][1] = 1;
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= i; j++) {
			int lftmy = my - j;
			int lftoth = oth - (i - j);
			if (lftmy < 0 || lftoth < 0) continue;
			dp[i + 1][j + 1] += dp[i][j] * ld(lftmy) / ld(lftmy + lftoth);
			dp[i + 1][j] += dp[i][j] * ld(lftoth) / ld(lftmy + lftoth);
		}
	for (int i = 1; i <= m && i <= n; i++)
		res += ld(i) / n * dp[n][i];
	cout << setprecision(16) << res << endl;
	return 0;
}