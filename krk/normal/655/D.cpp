#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, m;
int A[Maxn], B[Maxn];
vector <int> neigh[Maxn];
int dp[Maxn];
vector <int> my;
int bef[Maxn];

int Get(int x)
{
	if (dp[x] == -1) {
		dp[x] = 0;
		for (int i = 0; i < neigh[x].size(); i++)
			dp[x] = max(dp[x], Get(neigh[x][i]) + 1);
	}
	return dp[x];
}

int main()
{
	scanf("%d %d", &n, &m);
	fill(dp, dp + n + 1, -1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &A[i], &B[i]);
		neigh[A[i]].push_back(B[i]);
	}
	int mx = 0;
	for (int i = 1; i <= n; i++)
		mx = max(mx, Get(i));
	if (mx != n - 1) { printf("-1\n"); return 0; } 
	my.resize(n);
	for (int i = 1; i <= n; i++)
		my[Get(i)] = i;
	bef[my[0]] = -1;
	for (int i = 1; i < n; i++)
		bef[my[i]] = my[i - 1];
	for (int i = m - 1; i >= 0; i--)
		if (bef[A[i]] == B[i]) { printf("%d\n", i + 1); return 0; }
	return 0;
}