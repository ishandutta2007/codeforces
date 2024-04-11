#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 5005;
const int Inf = 1000000007;

int n, b;
vector <int> neigh[Maxn];
int c[Maxn], d[Maxn];
int dp[Maxn][2][Maxn];
int cnt[Maxn];

void Count(int v)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		Count(neigh[v][i]);
		cnt[v] += cnt[neigh[v][i]];
	}
}

void Traverse(int v)
{
	fill((int*)dp[v], (int*)dp[v] + 2 * Maxn, Inf);
	dp[v][0][0] = 0;
	dp[v][0][1] = c[v]; dp[v][1][1] = c[v] - d[v];
	vector <ii> seq;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		Traverse(u);
		seq.push_back(ii(cnt[u], u));
	}
	sort(seq.begin(), seq.end());
	int cur = 1;
	for (int i = 0; i < seq.size(); i++) {
		int u = seq[i].second;
		for (int j = cur; j >= 0; j--)
			for (int k = 1; k <= cnt[u]; k++) {
				dp[v][0][j + k] = min(dp[v][0][j + k], dp[v][0][j] + dp[u][0][k]);
				dp[v][1][j + k] = min(dp[v][1][j + k], dp[v][1][j] + min(dp[u][0][k], dp[u][1][k]));
			}
		cur += cnt[u];
	}
}

int main()
{
	scanf("%d %d", &n, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &c[i], &d[i]);
		if (i > 1) {
			int x; scanf("%d", &x);
			neigh[x].push_back(i);
		}
	}
	Count(1);
	Traverse(1);
	int i = 0;
	while (i <= n && min(dp[1][0][i], dp[1][1][i]) <= b) i++;
	printf("%d\n", i - 1);
	return 0;
}