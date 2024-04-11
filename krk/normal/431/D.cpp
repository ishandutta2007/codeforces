#include <cstdio>
#include <iostream>
using namespace std;

typedef unsigned long long ull;

const int Maxb = 64;

ull dp[Maxb][Maxb];
ull m;
int k;
ull res;

int main()
{
	dp[0][0] = 1;
	for (int i = 0; i + 1 < Maxb; i++)
		for (int j = 0; j <= i; j++) {
			dp[i + 1][j + 1] += dp[i][j];
			dp[i + 1][j] += dp[i][j];
		}
	cin >> m >> k; k--;
	for (int i = Maxb - 1; i >= 0; i--)
		if (m > dp[i][k]) { res |= ull(1) << i; m -= dp[i][k]; k--; }
	cout << res + 1 << endl;
	return 0;
}