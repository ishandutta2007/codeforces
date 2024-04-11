#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 20;
const int Maxl = 26;
const int Inf = 1000000000;

int n, m;
string s[Maxn];
int A[Maxn][Maxn];
int mask[Maxn][Maxl], cost[Maxn][Maxl];
int dp[Maxn + 1][1 << Maxn];
int ind[1 << Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &A[i][j]);
	for (int i = 0; i < n; i++)	
		for (int j = 0; j < m; j++) {
			mask[j][s[i][j] - 'a'] |= 1 << i;
			cost[j][s[i][j] - 'a'] += A[i][j];
		}
	for (int i = 0; i < n; i++)
		ind[1 << i] = i;
	fill((int*)dp, (int*)dp + (Maxn + 1) * (1 << Maxn), Inf);
	dp[0][0] = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 1 << n; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			int ij = j ^ ((1 << n) - 1);
			while (ij) {
				int val = ij & -ij;
				int l = ind[val];
				dp[i][j | 1 << l] = min(dp[i][j | 1 << l], dp[i][j] + A[l][i]);
				int nj = j | mask[i][s[l][i] - 'a'], add = cost[i][s[l][i] - 'a'] - A[l][i];
				dp[i][nj] = min(dp[i][nj], dp[i][j] + add);
				ij -= val;
			}
		}
	printf("%d\n", dp[m][(1 << n) - 1]);
	return 0;
}