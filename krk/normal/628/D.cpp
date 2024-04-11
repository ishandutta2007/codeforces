#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 2005;
const int mod = 1000000007;

int pw[Maxn];
int dp[Maxn][2][Maxn];
int m, d;
string a, b;

int Get(const string &s)
{
	int res = 0;
	int cur = 0;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < s[i] - '0'; j++) {
			if (i % 2 == 0 && j != d || i % 2 == 1 && j == d)
				res = (res + dp[s.length() - 1 - i][i % 2][cur]) % mod;
			cur = (cur - pw[s.length() - 1 - i] + m) % m;
		}
		if (i % 2 == 0 && s[i] - '0' == d || i % 2 == 1 && s[i] - '0' != d) return res;
	}
	return res + (cur == 0);
}

int main() 
{
	scanf("%d %d", &m, &d);
	pw[0] = 1 % m;
	for (int i = 1; i < Maxn; i++)
		pw[i] = pw[i - 1] * 10 % m;
	dp[0][0][0] = dp[0][1][0] = 1;
	for (int i = 0; i + 1 < Maxn; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < m; k++)
				for (int z = 0; z < 10; z++)
					if (i % 2 == j && z == d || i % 2 != j && z != d) {
						int nk = (10 * k + z) % m;
						dp[i + 1][j][nk] = (dp[i + 1][j][nk] + dp[i][j][k]) % mod;
					}
	cin >> a >> b;
	int p = a.length() - 1;
	while (a[p] == '0') p--;
	a[p]--;
	for (p++; p < a.length(); p++)
		a[p] = '9';
	printf("%d\n", (Get(b) - Get(a) + mod) % mod);
    return 0;
}