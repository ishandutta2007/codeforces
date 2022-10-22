#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 400005;

int n, m;
vector <ii> neigh[Maxn];
ii E[Maxn];
int cur, tim[Maxn], low[Maxn];
int dp[Maxn];

void Solve(int v, int p, int x)
{
	tim[v] = low[v] = ++cur;
	dp[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == p) continue;
		if (!tim[u.first]) {
			E[u.second] = ii(v, u.first);
			Solve(u.first, v, x);
			low[v] = min(low[u.first], low[v]);
			if (tim[v] < low[u.first]) {
				if (dp[u.first] < x) E[u.second] = ii(u.first, v);
				else dp[v] += dp[u.first];
			} else dp[v] += dp[u.first];
		} else {
			low[v] = min(low[v], tim[u.first]);
			if (tim[u.first] < tim[v]) E[u.second] = ii(v, u.first);
		}
	}
}

bool Ok(int x)
{
	cur = 0;
	fill(tim, tim + n + 1, 0); fill(low, low + n + 1, 0);
	Solve(1, 0, x);
	return dp[1] >= x;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &E[i].first, &E[i].second);
		neigh[E[i].first].push_back(ii(E[i].second, i));
		neigh[E[i].second].push_back(ii(E[i].first, i));
	}
	int l = 1, r = n;
	int res = 1;
	while (l <= r) {
		int m = l + r >> 1;
		if (Ok(m)) { res = m; l = m + 1; }
		else r = m - 1;
	}
	Ok(res);
	printf("%d\n", res);
	for (int i = 0; i < m; i++)
		printf("%d %d\n", E[i].first, E[i].second);
	return 0;
}