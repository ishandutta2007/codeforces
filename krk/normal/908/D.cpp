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

const int mod = 1000000007;
const int Maxn = 1005;

int k, pa, pb;
int tmpa, tmpb;
int dp[Maxn][Maxn];

int Inv(int x)
{
	int res = 1;
	int p = mod - 2;
	while (p) {
		if (p & 1) res = ll(res) * x % mod;
		p >>= 1; x = ll(x) * x % mod;
	}
	return res;
}

int main()
{
	scanf("%d %d %d", &k, &tmpa, &tmpb);
	pa = ll(tmpa) * Inv(tmpa + tmpb) % mod;
	pb = ll(tmpb) * Inv(tmpa + tmpb) % mod;
	int spec = ll(pa) * Inv(pb) % mod;
	for (int i = 1; i <= k; i++) {
		for (int j = i; j <= k; j++)
			dp[i][j] = (spec + j) % mod;
		for (int j = i - 1; j >= 1; j--)
			dp[i][j] = (ll(pa) * dp[i][j + 1] + ll(pb) * ll(j + dp[i - j][j]) % mod) % mod;
	}
	printf("%d\n", dp[k][1]);
	return 0;
}