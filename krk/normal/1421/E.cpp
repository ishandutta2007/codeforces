#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll Inf = 4000000000000000000ll;

int n;
ll dp[Maxn][3][2][2];

int getJ(int old, int nw)
{
	if (nw == 0)
		if (old == 0) return 1;
		else if (old == 1) return 2;
		else return 0;
	else if (old == 0) return 2;
	     else if (old == 1) return 0;
	     else return 1;
}

int main()
{
	scanf("%d", &n);
	int a; scanf("%d", &a);
	if (n == 1) { printf("%d\n", a); return 0; }
	fill((ll*)dp, (ll*)dp + Maxn * 3 * 2 * 2, -Inf);
	dp[1][1][1][0] = a;
	dp[1][0][0][0] = -a;
	for (int i = 1; i < n; i++) {
		scanf("%d", &a);
		for (int j = 0; j < 3; j++)
			for (int l = 0; l < 2; l++)
				for (int k = 0; k < 2; k++) {
					// -
					int nj = getJ(j, 0);
					int nl = 0;
					int nk = (k == 1 || l == 0);
					dp[i + 1][nj][nl][nk] = max(dp[i + 1][nj][nl][nk], dp[i][j][l][k] - a);
					// +
					nj = getJ(j, 1);
					nl = 1;
					nk = (k == 1 || l == 1);
					dp[i + 1][nj][nl][nk] = max(dp[i + 1][nj][nl][nk], dp[i][j][l][k] + a);
				}
	}
	printf("%I64d\n", max(dp[n][1][0][1], dp[n][1][1][1]));
    return 0;
}