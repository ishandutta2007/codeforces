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

typedef long long ll;

const int Maxb = 11;
const int Maxd = 65;
const int Maxm = 1 << Maxb;

ll dp[Maxb][Maxd][Maxm], has[Maxb][Maxd];
int t;
int b;
ll l, r;

ll Get(int b, ll x)
{
	string s;
	while (x) {
		s += char(x % b + '0');
		x /= b;
	}
	reverse(s.begin(), s.end());
	ll res = has[b][int(s.length()) - 1];
	int mask = 0;
	for (int i = 0; i < s.length(); i++) {
		int from = i == 0? 1: 0;
		for (int j = from; j < s[i] - '0'; j++)
			res += dp[b][int(s.length()) - 1 - i][mask ^ 1 << j];
		mask ^= 1 << int(s[i] - '0');
	}
	return res;
}

int main()
{
	for (int i = 2; i < Maxb; i++) {
		dp[i][0][0] = 1; has[i][0] = 0;
		for (int j = 1; j < Maxd; j++) {
			for (int m = 0; m < 1 << i; m++)
				for (int k = 0; k < i; k++)
					dp[i][j][m] += dp[i][j - 1][m ^ 1 << k];
			has[i][j] += has[i][j - 1];
			for (int d = 1; d < i; d++)
				has[i][j] += dp[i][j - 1][1 << d];
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d %I64d %I64d", &b, &l, &r);
		ll res = Get(b, r + 1) - Get(b, l);
		printf("%I64d\n", res);
	}
	return 0;
}