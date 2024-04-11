#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 410005;
const int nil = 205000;
const int mod = 1000000007;

int a, b, k, t;
int dp[2][Maxn], cur;
int res;

int main()
{
	scanf("%d %d %d %d", &a, &b, &k, &t);
	dp[cur][a - b + nil] = 1; dp[cur][a - b + nil + 1] = mod - 1;
	for (int i = 0; i < 2 * t; i++) {
		int add = 0;
		for (int j = 0; j < Maxn; j++) {
			add = (add + dp[cur][j]) % mod; dp[cur][j] = 0;
			if (add != 0) {
				dp[!cur][j - k] = (dp[!cur][j - k] + add) % mod;
				dp[!cur][j + k + 1] = (dp[!cur][j + k + 1] - add + mod) % mod;
			}
		}
		cur = !cur;
	}
	int add = 0;
	for (int j = 0; j < Maxn; j++) {
		add = (add + dp[cur][j]) % mod;
		if (j > nil) res = (res + add) % mod;
	}
	printf("%d\n", res);
	return 0;
}