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
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

char str[Maxn];
string S, T;
int Z[Maxn];
vector <vector <int> > dp;

void Read(string &s)
{
	scanf("%s", str); s = str;
}

bool Check(int a)
{
	if (a + T.length() > S.length()) return false;
	for (int i = 0; i < T.length(); i++)
		if (S[a + i] != '?' && S[a + i] != T[i]) return false;
	return true;
}

int main()
{
	Read(S);
	Read(T);
	int l = -1, r = -1;
	for (int i = 1; i < T.length(); i++) {
		if (i <= r) Z[i] = min(Z[i - l], r - i);
		while (i + Z[i] < T.length() && T[Z[i]] == T[i + Z[i]]) Z[i]++;
		if (i + Z[i] - 1 > r) {
			r = i + Z[i] - 1; l = i;
		}
	}
	dp.resize(S.length() + 1, vector <int>(T.length() + 1, -Maxn));
	dp[0][T.length()] = 0;
	for (int i = 0; i < S.length(); i++) {
		bool ok = Check(i);
		for (int j = 1; j <= T.length(); j++) {
			int nj = min(j + 1, int(T.length()));
			dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j]);
			if (ok && j + Z[j] >= T.length()) dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + 1);
		}
	}
	printf("%d\n", dp[S.length()][T.length()]);
	return 0;
}