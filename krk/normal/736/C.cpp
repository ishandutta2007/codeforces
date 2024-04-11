#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 102;
const int Maxc = 23;
const int Maxm = 45;
const int mod = 1000000007;

int n, k;
vector <int> neigh[Maxn];
int dp[Maxn][Maxc][Maxm];

void Traverse(int v, int p = 0)
{
	dp[v][1][2 * k + 1] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
		for (int c1 = Maxc - 1; c1 >= 0; c1--)
			for (int m1 = 0; m1 < Maxm; m1++) if (dp[v][c1][m1] > 0) {
				int val = dp[v][c1][m1]; dp[v][c1][m1] = 0;
				for (int c2 = Maxc - 1; c2 >= 0; c2--)
					for (int m2 = 0; m2 < Maxm; m2++) if (dp[u][c2][m2] > 0) {
						int c3 = max(c1, c2), m3 = min(m1, m2);
						dp[v][c3][m3] = (dp[v][c3][m3] + ll(val) * dp[u][c2][m2]) % mod;
					}
			}
	}
	for (int c1 = 1; c1 < Maxc; c1++)
		for (int m1 = 0; m1 < Maxm; m1++) if (c1 - 1 + m1 <= k) {
			int val = dp[v][c1][m1]; dp[v][c1][m1] = 0;
			dp[v][0][m1] = (dp[v][0][m1] + val) % mod;
		}
	for (int c1 = 0; c1 <= k + 1; c1++)
		for (int m1 = 0; m1 < Maxm; m1++)
			dp[v][0][0] = (dp[v][0][0] + dp[v][c1][m1]) % mod;
	if (v != 1) {
		for (int i = Maxc - 1; i >= 0; i--)
			for (int j = Maxm - 1; j >= 0; j--) {
				dp[v][i][j] = 0;
				if (i > 0) {
					if (i > 1 && j > 0) dp[v][i][j] = dp[v][i - 1][j - 1];
				} else if (j > 0) dp[v][0][j] = dp[v][0][j - 1];
			}
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	if (k == 0) { printf("1\n"); return 0; }
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	int res = 0;
	for (int j = 0; j <= k; j++)
		res = (res + dp[1][0][j]) % mod;
	printf("%d\n", res);
	return 0;
}