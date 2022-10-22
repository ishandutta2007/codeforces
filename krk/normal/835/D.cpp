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

const int Maxn = 5005;

string s;
bool pal[Maxn][Maxn];
int dp[Maxn][Maxn];
int res[Maxn];

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		dp[i][i] = 1;
		pal[i][i] = 1;
	}
	for (int l = 1; l < s.length(); l++)
		for (int i = 0; i + l < s.length(); i++) {
			int j = i + l;
			if (s[i] == s[j] && (l == 1 || pal[i + 1][j - 1])) pal[i][j] = true;
			int mid = (j - i + 1) / 2;
			if (pal[i][j]) dp[i][j] = max(dp[i][i + mid - 1], dp[j - mid + 1][j]) + 1;
		}
	for (int i = 0; i < s.length(); i++)
		for (int j = i; j < s.length(); j++)
			if (dp[i][j] > 0) res[dp[i][j]]++;
	for (int i = s.length(); i >= 0; i--)
		res[i] += res[i + 1];
	for (int i = 1; i <= s.length(); i++)
		printf("%d%c", res[i], i + 1 <= s.length()? ' ': '\n');
	return 0;
}