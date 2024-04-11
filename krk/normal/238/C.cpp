#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 3005;

int n;
vector <ii> neigh[Maxn];
int dp[Maxn][3];
int res = Maxn;

void Get(int v, int p)
{
	dp[v][0] = 0;
	int best1 = 0, best2 = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == p) continue;
		Get(u.first, v);
		dp[v][0] += dp[u.first][0] + u.second;
		best1 = max(best1, dp[u.first][0] + u.second - dp[u.first][2] - u.second);
		best1 = max(best1, dp[u.first][0] + u.second - dp[u.first][1] - u.second);
		best2 = max(best2, dp[u.first][0] + u.second - dp[u.first][2] - !u.second);
	}
	dp[v][1] = dp[v][0] - best1; dp[v][2] = dp[v][0] - best2;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(ii(b, 0)); neigh[b].push_back(ii(a, 1));
	}
	for (int i = 1; i <= n; i++) {
		Get(i, 0);
		res = min(res, min(dp[i][1], dp[i][2]));
	}
	printf("%d\n", res);
	return 0;
}