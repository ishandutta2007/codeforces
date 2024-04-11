#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxg = 301;
const int Maxn = 100005;

int n, m, s, e;
int a[Maxn], b[Maxn];
vector <int> ind[Maxn];
int pnt[Maxn];
int dp[Maxg][Maxn];
int res;

int main()
{
	scanf("%d %d %d %d", &n, &m, &s, &e);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		ind[a[i]].push_back(i);
	}
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i < Maxg; i++) {
		for (int j = 0; j < Maxn; j++)
			pnt[j] = int(ind[j].size()) - 1;
		dp[i][0] = n + 1;
		int mndiam = n + m + 1;
		for (int j = 1; j <= m; j++) {
			while (pnt[b[j]] >= 0 && dp[i - 1][j - 1] < ind[b[j]][pnt[b[j]]]) pnt[b[j]]--;
			dp[i][j] = dp[i][j - 1];
			if (pnt[b[j]] + 1 < ind[b[j]].size())
				dp[i][j] = min(dp[i][j], ind[b[j]][pnt[b[j]] + 1]);
			if (dp[i][j] <= n) mndiam = min(mndiam, j + dp[i][j]);
		}
		if (mndiam <= n + m && i * e + mndiam <= s)
			res = i;
	}
	printf("%d\n", res);
	return 0;
}