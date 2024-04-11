#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Inf = 1000000000;
const int Maxn = 50005;
const int Maxl = 26;
const int Maxm = 55;

char s[Maxn];
int n;
int lst[Maxn][Maxl];
int dp[Maxn][Maxm];
bool tk[Maxn][Maxm];
vector <char> res;
char sp = '?';

void Collect(int r, int c)
{
	if (r == 0) return;
	if (!tk[r][c]) Collect(r - 1, c);
	else {
		res.push_back(s[r - 1]);
		Collect(r - 1, c - 1);
	}
}

int main()
{
	scanf("%s", s); n = strlen(s);
	fill(lst[0], lst[0] + Maxl, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < Maxl; j++) lst[i + 1][j] = lst[i][j];
		lst[i + 1][s[i] - 'a'] = i;
	}
	fill((int*)dp, (int*)dp + Maxn * Maxm, -Inf); dp[0][0] = n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < Maxm; j++) if (dp[i][j] != -Inf) {
			if (dp[i][j] > dp[i + 1][j]) { dp[i + 1][j] = dp[i][j]; tk[i + 1][j] = false; }
			int pos = lst[dp[i][j]][s[i] - 'a'];
			if (i < pos && pos > dp[i + 1][j + 1]) { dp[i + 1][j + 1] = pos; tk[i + 1][j + 1] = true; }
		}
	if (dp[n][50] != -Inf) Collect(n, 50);
	else {
		int t = 50;
		while (dp[n][t] == -Inf) t--;
		int i;
		for (i = 0; i < n; i++)
			if (i < dp[i][t]) { sp = s[i]; break; }
		Collect(i, t);
	}
	for (int i = int(res.size()) - 1; i >= 0; i--)
		printf("%c", res[i]);
	if (sp != '?') printf("%c", sp);
	for (int i = 0; i < res.size(); i++)
		printf("%c", res[i]);
	printf("\n");
	return 0;
}