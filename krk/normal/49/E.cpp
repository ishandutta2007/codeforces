#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 52;
const int Maxl = 26;
const int Inf = 1000000000;

string s1, s2;
int n;
vector <ii> neigh[Maxl];
int dp1[Maxn][Maxn][Maxl];
int dp2[Maxn][Maxn][Maxl];
int dp[Maxn][Maxn];

int Prec(const string &s, int dp[][Maxn][Maxl], int l, int r, int ch)
{
	if (dp[l][r][ch] == 0)
		if (l == r) dp[l][r][ch] = s[l] == 'a' + ch? 1: -1;
		else {
			dp[l][r][ch] = -1;
			for (int i = 0; i < neigh[ch].size(); i++) {
				ii u = neigh[ch][i];
				int j;
				for (j = l; j < r; j++)
					if (Prec(s, dp, l, j, u.first) == 1 && Prec(s, dp, j + 1, r, u.second) == 1) break;
				if (j < r) { dp[l][r][ch] = 1; break; }
			}
		}
	return dp[l][r][ch];
}

void Proc(const string &s, int dp[][Maxn][Maxl])
{
	for (int i = 0; i < s.length(); i++)
		for (int j = i; j < s.length(); j++)
			for (int ch = 0; ch < Maxl; ch++) {
				dp[i][j][ch] = Prec(s, dp, i, j, ch);
			}
}

int main()
{
	char s[10];
	cin >> s1;
	cin >> s2;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		neigh[s[0] - 'a'].push_back(ii(s[3] - 'a', s[4] - 'a'));
	}
	Proc(s1, dp1); Proc(s2, dp2);
	fill((int*)dp, (int*)dp + Maxn * Maxn, Inf); dp[0][0] = 0;
	for (int i = 0; i < s1.length(); i++)
		for (int j = 0; j < s2.length(); j++) if (dp[i][j] != Inf)
			for (int ch = 0; ch < Maxl; ch++)
				for (int i2 = i; i2 < s1.length(); i2++) if (dp1[i][i2][ch] == 1)
					for (int j2 = j; j2 < s2.length(); j2++) if (dp2[j][j2][ch] == 1)
						dp[i2 + 1][j2 + 1] = min(dp[i2 + 1][j2 + 1], dp[i][j] + 1);
	int res = dp[s1.length()][s2.length()];
	printf("%d\n", res == Inf? -1: res);
	return 0;
}