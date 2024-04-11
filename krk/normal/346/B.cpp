#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int Maxn = 105;
const int Maxl = 26;

string s1, s2, virus;
int nk[Maxn][Maxl];
int dp[Maxn][Maxn][Maxn];
int par[Maxn][Maxn][Maxn], wth[Maxn][Maxn][Maxn];

bool Equal(int l, int i, int j)
{
	if (virus[l - 1] != 'A' + j) return false;
	for (int k = l - 2, z = i - 1; k >= 0; k--, z--)
		if (virus[k] != virus[z]) return false;
	return true;
}

int findNk(int i, int j)
{
	for (int l = i + 1; l > 0; l--)
		if (Equal(l, i, j)) return l;
	return 0;
}

void Print(int i, int j, int k)
{
	if (dp[i][j][k] == 0) return;
	if (par[i][j][k] == 0) { Print(i - 1, j, k); return; }
	if (par[i][j][k] == 1) { Print(i, j - 1, k); return; }
	if (par[i][j][k] == 2) Print(i - 1, j - 1, wth[i][j][k]);
	printf("%c", s1[i - 1]);
}

int main()
{
	cin >> s1 >> s2 >> virus;
	for (int i = 0; i < virus.length(); i++)
		for (int j = 0; j < Maxl; j++)
			nk[i][j] = findNk(i, j);
	for (int i = 0; i <= s1.length(); i++)
		for (int j = 0; j <= s2.length(); j++)
			for (int k = 0; k < virus.length(); k++) {
				if (i + 1 <= s1.length() && dp[i][j][k] > dp[i + 1][j][k]) {
					dp[i + 1][j][k] = dp[i][j][k]; par[i + 1][j][k] = 0;
				}
				if (j + 1 <= s2.length() && dp[i][j][k] > dp[i][j + 1][k]) {
					dp[i][j + 1][k] = dp[i][j][k]; par[i][j + 1][k] = 1;
				}
				if (i + 1 <= s1.length() && j + 1 <= s2.length() && s1[i] == s2[j])
					if (dp[i][j][k] + 1 > dp[i + 1][j + 1][nk[k][s1[i] - 'A']]) {
						dp[i + 1][j + 1][nk[k][s1[i] - 'A']] = dp[i][j][k] + 1; 
						par[i + 1][j + 1][nk[k][s1[i] - 'A']] = 2; wth[i + 1][j + 1][nk[k][s1[i] - 'A']] = k;
					}
			}
	int k = 0;
	for (int l = 0; l < virus.length(); l++)
		if (dp[s1.length()][s2.length()][l] > dp[s1.length()][s2.length()][k]) k = l;
	if (dp[s1.length()][s2.length()][k]) { Print(s1.length(), s2.length(), k); printf("\n"); }
	else printf("0\n");
	return 0;
}