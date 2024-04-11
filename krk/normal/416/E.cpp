#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Inf = 1000000000;
const int Maxn = 505;
const int Maxm = Maxn * Maxn;

int n, m;
int a[Maxm], b[Maxm], l[Maxm];
int dist[Maxn][Maxn];
int cnt[Maxn];
int res[Maxn][Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = i == j? 0: Inf;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &l[i]);
		dist[a[i]][b[i]] = dist[b[i]][a[i]] = l[i];
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	for (int i = 1; i <= n; i++) {
		fill(cnt + 1, cnt + n + 1, 0);
		for (int j = 0; j < m; j++)
			if (dist[i][b[j]] == dist[i][a[j]] + l[j]) cnt[b[j]]++;
			else if (dist[i][a[j]] == dist[i][b[j]] + l[j]) cnt[a[j]]++;
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (dist[i][k] + dist[k][j] == dist[i][j]) res[i][j] += cnt[k];
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			printf("%d%c", res[i][j], i == n - 1 && j == n? '\n': ' ');
	return 0;
}