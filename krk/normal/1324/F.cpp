#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
vector <int> neigh[Maxn];
int dp[Maxn];
int res[Maxn];

void Traverse(int v, int p)
{
	dp[v] = a[v];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
		dp[v] += max(0, dp[u]);
	}
}

void Solve(int v, int p, int tp)
{
	res[v] = dp[v] + tp;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Solve(u, v, max(0, res[v] - max(0, dp[u])));
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) a[i] = -1;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1, 0);
	Solve(1, 0, 0);
	for (int i = 1; i <= n; i++)
		printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}