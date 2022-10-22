#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int Maxn = 5005;

string s;
int has[Maxn][Maxn];
int q;

int main()
{
	cin >> s;
	for (int i = 1; i <= s.length(); i++) {
		has[i][i] = 1; has[i][i + 1] = i < s.length() && s[i - 1] == s[i];
	}
	for (int j = 3; j <= s.length(); j++)
		for (int i = 1; i + j <= s.length() + 1; i++)
			has[i][i + j - 1] = s[i - 1] == s[i + j - 2] && has[i + 1][i + j - 2];
	for (int i = 1; i <= s.length(); i++)
		for (int j = i + 1; j <= s.length(); j++)
			has[i][j] += has[i][j - 1];
	for (int i = s.length() - 1; i >= 1; i--)
		for (int j = i + 1; j <= s.length(); j++)
			has[i][j] += has[i + 1][j];
	scanf("%d", &q);
	while (q--) {
		int l, r; scanf("%d %d", &l, &r);
		printf("%d\n", has[l][r]);
	}
	return 0;
}