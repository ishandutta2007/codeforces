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

const int mod = 1000000007;
const int Maxn = 1005;

int C[Maxn][Maxn];
string s;
int k;
int dp[Maxn];
int res;

void Add(int was, int len)
{
	for (int i = 0; i <= len; i++) if (was + i > 0) {
		int ways = C[len][i];
		if (dp[was + i] + 1 == k) res = (res + ways) % mod;
	}
}

int main()
{
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	cin >> s;
	cin >> k;
	if (k == 0) { printf("1\n"); return 0; }
	for (int i = 2; i < Maxn; i++)
		dp[i] = dp[__builtin_popcount(i)] + 1;
	int has = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '1') { Add(has, int(s.length()) - i - 1); has++; } 
	Add(has, 0);
	if (k == 1) res = (res - 1 + mod) % mod;
	printf("%d\n", res);
	return 0;
}