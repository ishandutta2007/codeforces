#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

const int Maxn = 2005;

string s;
bool dp[Maxn][Maxn];
int was[Maxn];
ll res;

int main()
{
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		dp[i][i] = true;
		if (i + 1 < s.length() && s[i] == s[i + 1]) dp[i][i + 1] = true;
	}
	for (int j = 2; j < s.length(); j++)
		for (int i = 0; i + j < s.length(); i++)
			dp[i][i + j] = s[i] == s[i + j] && dp[i + 1][i + j - 1];
	for (int i = 0; i < s.length(); i++) {
		if (i) was[i] = was[i - 1];
		for (int j = 0; j <= i; j++)
			if (dp[j][i]) { was[i]++; if (j) res += was[j - 1]; }
	}
	printf("%I64d\n", res);
	return 0;
}