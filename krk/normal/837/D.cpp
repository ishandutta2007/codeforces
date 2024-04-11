#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 205;
const int Maxm = 27 * Maxn;

int n, k;
ll a;
int dp[Maxn][Maxm];

int main()
{
	scanf("%d %d", &n, &k);
	fill((int*)dp, (int*)dp + Maxn * Maxm, -1);
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &a);
		int twos = 0, fives = 0;
		while (a % 2 == 0) { twos++; a /= 2; }
		while (a % 5 == 0) { fives++; a /= 5; }
		for (int j = k - 1; j >= 0; j--)
			for (int l = Maxm - fives - 1; l >= 0; l--) if (dp[j][l] >= 0)
				dp[j + 1][l + fives] = max(dp[j + 1][l + fives], dp[j][l] + twos);
	}
	int res = 0;
	for (int l = 0; l < Maxm; l++)
		res = max(res, min(l, dp[k][l]));
	printf("%d\n", res);
	return 0;
}