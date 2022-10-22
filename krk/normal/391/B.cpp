#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

string s;
int dp[Maxn];
int res;

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) if ((i - j) % 2 && s[j] == s[i])
			dp[i] = max(dp[i], dp[j] + 1);
		res = max(res, dp[i]);
	}
	printf("%d\n", res);
	return 0;
}