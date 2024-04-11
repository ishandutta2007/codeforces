#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int dp[Maxn];
int q;

bool Prime(int x)
{
	if (x <= 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return false;
	return true;
}

int main()
{
	dp[0] = 0;
	for (int i = 1; i < Maxn; i++) {
		dp[i] = -1;
		for (int j = 2; j <= i; j++) if (!Prime(j) && dp[i - j] != -1)
			dp[i] = max(dp[i], 1 + dp[i - j]);
	}
	scanf("%d", &q);
	while (q--) {
		int n; scanf("%d", &n);
		if (n < 12) printf("%d\n", dp[n]);
		else {
			int res = n / 4;
			if (n % 2) res--;
			printf("%d\n", res);
		}
	}
	return 0;
}