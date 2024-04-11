#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef long long ll;

const int Maxn = 305;
const int Maxm = 100005;
const ll Inf = 1000000000000000000ll;

int n, m, k;
iii S[Maxm];
int neigh[Maxn][Maxn], to[Maxn];
ll dp[Maxn][Maxn], res = Inf;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &S[i].second.first, &S[i].second.second, &S[i].first);
	sort(S, S + m);
	for (int i = 1; i <= n; i++) {
		to[i] = i;
		for (int j = 0; j < m; j++)
			if (S[j].second.first <= i)
				while (to[i] < S[j].second.second + 1) neigh[i][++to[i]] = S[j].first;
	}
	fill((ll*)dp, (ll*)dp + Maxn * Maxn, Inf); dp[1][0] = 0ll;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			for (int k = i + 1; k <= to[i]; k++)
				dp[k][j + k - i] = min(dp[k][j + k - i], dp[i][j] + neigh[i][k]);
		}
	for (int j = k; j <= n; j++)
		res = min(res, dp[n + 1][j]);
	printf("%I64d\n", res == Inf? -1ll: res);
	return 0;
}