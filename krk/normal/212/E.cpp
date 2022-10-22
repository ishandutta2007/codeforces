#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 5005;

int n;
vector <int> neigh[Maxn];
int sum[Maxn];
bool dp[Maxn][Maxn];
bool found[Maxn];
vector <int> res;

void Get(int v, int p)
{
	sum[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Get(u, v);
		sum[v] += sum[u];
	}
	dp[v][0] = dp[v][n - sum[v]] = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		for (int j = n - sum[u]; j >= 0; j--)
			dp[v][j + sum[u]] |= dp[v][j];
	}
	for (int i = 1; i < n - 1; i++)
		found[i] |= dp[v][i];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	Get(1, 0);
	for (int i = 0; i <= n; i++)
		if (found[i]) res.push_back(i);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i], n - 1 - res[i]);
	return 0;
}