#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxl = 26;
const int Maxn = 1005;
const int Inf = 1000000000;

string s;
int freq[Maxl];
int n;
int dp[Maxl + 1][Maxn], par[Maxl + 1][Maxn];

void Print(int r, int c)
{
	if (!r) return;
	int hm = par[r][c];
	Print(r - 1, c - par[r][c]);
	for (int i = 0; i < par[r][c]; i++)
		printf("%c", 'a' + r - 1);
}

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		freq[s[i] - 'a']++;
	scanf("%d", &n);
	fill((int*)dp, (int*)dp + (Maxl + 1) * Maxn, Inf); dp[0][0] = 0;
	for (int i = 0; i < Maxl; i++)
		for (int j = 0; j <= n; j++) if (dp[i][j] < Inf) {
			if (freq[i] == 0 && dp[i][j] < dp[i + 1][j]) { dp[i + 1][j] = dp[i][j]; par[i + 1][j] = 0; }
			for (int k = 1; j + k <= n; k++) {
				int cand = max(dp[i][j], freq[i] / k + (freq[i] % k > 0));
				if (cand < dp[i + 1][j + k]) { dp[i + 1][j + k] = cand; par[i + 1][j + k] = k; }
			}
		}
	if (dp[Maxl][n] == Inf) printf("-1\n");
	else {
		printf("%d\n", dp[Maxl][n]);
		Print(Maxl, n); printf("\n");
	}
	return 0;
}