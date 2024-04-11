#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Inf = 2000000000;
const int Maxn = 4005;
const int Maxl = 26;

int ti, td, tr, te;
string a, b;
int nxta[Maxn][Maxl], nxtb[Maxn][Maxl];
int dp[Maxn][Maxn];

int main()
{
	scanf("%d %d %d %d", &ti, &td, &tr, &te);
	cin >> a >> b;
	for (int i = 0; i < Maxl; i++) nxta[a.length()][i] = a.length();
	for (int i = a.length() - 1; i >= 0; i--)
		for (int j = 0; j < Maxl; j++)
			nxta[i][j] = a[i] == 'a' + j? i: nxta[i + 1][j];
	for (int i = 0; i < Maxl; i++) nxtb[b.length()][i] = b.length();
	for (int i = b.length() - 1; i >= 0; i--)
		for (int j = 0; j < Maxl; j++)
			nxtb[i][j] = b[i] == 'a' + j? i: nxtb[i + 1][j];
	fill((int*)dp, (int*)dp + Maxn * Maxn, Inf); dp[0][0] = 0;
	for (int i = 0; i <= a.length(); i++)
		for (int j = 0; j <= b.length(); j++) {
			// Insert
			if (j < b.length()) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + ti);
			// Delete
			if (i < a.length()) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + td);
			// Replace
			if (i < a.length() && j < b.length()) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (a[i] != b[j]) * tr);
			// Swap
			if (i + 1 < a.length() && j + 1 < b.length()) {
				int nxti = nxta[i + 1][b[j] - 'a'], nxtj = nxtb[j + 1][a[i] - 'a'];
				if (nxti < a.length() && nxtj < b.length()) {
					int cost = (nxti - i - 1) * td + te + (nxtj - j - 1) * ti;
					dp[nxti + 1][nxtj + 1] = min(dp[nxti + 1][nxtj + 1], dp[i][j] + cost);
				}
			}
		}
	printf("%d\n", dp[a.length()][b.length()]);
	return 0;
}