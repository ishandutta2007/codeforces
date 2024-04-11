#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
const int Inf = 1000000000;

string S[2];
int dp[Maxn][2][2];
int res;

bool Okay(bool a, bool b, int ind, int cur, bool &na, bool &nb)
{
	if (ind + 1 >= S[0].length()) return false;
	if (cur == 0)
		if (!a && !b && S[0][ind + 1] != 'X') {
			na = true;
			nb = S[1][ind + 1] == 'X';
			return true;
		} else return false;
	else if (cur == 1)
		if (!a && !b && S[1][ind + 1] != 'X') {
			na = S[0][ind + 1] == 'X';
			nb = true;
			return true;
		} else return false;
	else if (cur == 2)
		if (!a && S[0][ind + 1] != 'X' && S[1][ind + 1] != 'X') {
			na = nb = true;
			return true;
		} else return false;
	else if (cur == 3)
		if (!b && S[0][ind + 1] != 'X' && S[1][ind + 1] != 'X') {
			na = nb = true;
			return true;
		} else return false;
}

int main()
{
	cin >> S[0];
	cin >> S[1];
	fill((int*)dp, (int*)dp + Maxn * 2 * 2, -Inf);
	dp[0][S[0][0] == 'X'][S[1][0] == 'X'] = 0;
	for (int i = 0; i < S[0].length(); i++)
		for (int a = 0; a < 2; a++)
			for (int b = 0; b < 2; b++) if (dp[i][a][b] >= 0) {
				res = max(res, dp[i][a][b]);
				bool na, nb;
				for (int j = 0; j < 4; j++) if (Okay(a, b, i, j, na, nb))
					dp[i + 1][na][nb] = max(dp[i + 1][na][nb], dp[i][a][b] + 1);
				na = i + 1 < S[0].length() && S[0][i + 1] == 'X';
				nb = i + 1 < S[1].length() && S[1][i + 1] == 'X';
				dp[i + 1][na][nb] = max(dp[i + 1][na][nb], dp[i][a][b]);
			}
	printf("%d\n", res);
	return 0;
}