#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 18;

int n;
ld B[Maxn][Maxn];
ld dp[1 << Maxn][Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> B[i][j];
	int all = (1 << n) - 1;
	for (int i = 0; i < n; i++)
		dp[all][i] = int(i == 0);
	for (int i = all - 1; i > 0; i--)
		for (int j = 0; j < n; j++) if (i & 1 << j)
			for (int l = 0; l < n; l++) if (!(i & 1 << l))
				dp[i][j] = max(dp[i][j], B[j][l] * dp[i | 1 << l][j] + B[l][j] * dp[i | 1 << l][l]);
	ld res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, dp[1 << i][i]);
	cout << fixed << setprecision(15) << res << endl;
	return 0;
}