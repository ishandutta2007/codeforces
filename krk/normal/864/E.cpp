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

typedef pair <int, int> ii;

const int Maxn = 105;
const int Maxm = 3005;
const int Inf = 1000000000;

int n;
int t[Maxn], d[Maxn], p[Maxn];
vector <ii> seq;
int dp[Maxn][Maxm], par[Maxn][Maxm];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &t[i], &d[i], &p[i]);
		seq.push_back(ii(d[i] - 1, i));
	}
	sort(seq.begin(), seq.end());
	fill((int*)dp, (int*)dp + Maxn * Maxm, -Inf); dp[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < Maxm; j++) if (dp[i][j] >= 0) {
			if (dp[i][j] > dp[i + 1][j]) { dp[i + 1][j] = dp[i][j]; par[i + 1][j] = -1; }
			if (j + t[seq[i].second] <= seq[i].first && dp[i][j] + p[seq[i].second] > dp[i + 1][j + t[seq[i].second]]) {
				dp[i + 1][j + t[seq[i].second]] = dp[i][j] + p[seq[i].second];
				par[i + 1][j + t[seq[i].second]] = seq[i].second;
			}
		}
	int nj = 0;
	for (int j = 0; j < Maxm; j++)
		if (dp[n][j] > dp[n][nj]) nj = j;
	int ni = n;
	printf("%d\n", dp[ni][nj]);
	vector <int> seq;
	while (ni > 0)
		if (par[ni][nj] == -1) ni--;
		else { seq.push_back(par[ni][nj]); nj -= t[par[ni][nj]]; ni--; }
	reverse(seq.begin(), seq.end());
	printf("%d\n", seq.size());
	for (int i = 0; i < seq.size(); i++)
		printf("%d%c", seq[i] + 1, i + 1 < seq.size()? ' ': '\n');
	return 0;
}