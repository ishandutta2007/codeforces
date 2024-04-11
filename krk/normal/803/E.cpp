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

const int Maxn = 1005;
const int nil = Maxn;
const int Maxm = 2015;

int n, k;
string s;
bool dp[Maxn][Maxm];
int par[Maxn][Maxm];

void Print(int r, int c)
{
	if (r == 0) return;
	Print(r - 1, par[r][c]);
	if (par[r][c] < c) s[r - 1] = 'W';
	else if (par[r][c] > c) s[r - 1] = 'L';
	else s[r - 1] = 'D';
}

int main()
{
	scanf("%d %d", &n, &k);
	cin >> s;
	dp[0][nil] = true;
	for (int i = 0; i < n; i++)
		for (int j = nil - k + 1; j < nil + k; j++) if (dp[i][j]) {
			if (s[i] == 'W' || s[i] == '?') { dp[i + 1][j + 1] = true; par[i + 1][j + 1] = j; }
			if (s[i] == 'L' || s[i] == '?') { dp[i + 1][j - 1] = true; par[i + 1][j - 1] = j; }
			if (s[i] == 'D' || s[i] == '?') { dp[i + 1][j] = true; par[i + 1][j] = j; }
		}
	if (dp[n][nil - k]) {
		Print(n, nil - k);
		printf("%s\n", s.c_str());
	} else if (dp[n][nil + k]) {
		Print(n, nil + k);
		printf("%s\n", s.c_str());
	} else printf("NO\n"); 
	return 0;
}