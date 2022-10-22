#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#ifdef LOCAL
const int LIM = 13;
#else
const int LIM = 200500;
#endif
const int INF = 1e+9 + 7;
const ld EPS = 1e-7;

#ifdef LOCAL
//#define STRESS
#endif

vector<int> graph[LIM];
int par[LIM];
int siz[LIM];
ll lvl[LIM][5];
ll dp[LIM][5];

int k;
void dfs(int v)
{
	siz[v] = 1;
	for (int i = 0; i < graph[v].size(); ++i)
	{
		int u = graph[v][i];
		if (u != par[v])
		{
			par[u] = v;
			dfs(u);
			siz[v] += siz[u];
			for (int j = 0; j < k; ++j)
				lvl[v][(j + 1) % k] += lvl[u][j];
			for (int j1 = 0; j1 < k; ++j1)
				for (int j2 = 0; j2 < k; ++j2)
					dp[v][(j1 + j2) % k] += lvl[u][(j1 + k - 1) % k] * (lvl[v][j2] - lvl[u][(j2 + k - 1) % k]);
		}
	}
	lvl[v][0] += 1;
}

void solve()
{
	int n;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	par[0] = -1;
	dfs(0);
	ll len_sum = 0;
	for (int i = 0; i < n; ++i)
		len_sum += (ll)siz[i] * (ll)(n - siz[i]);
	for (int j = 1; j < k; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			len_sum += (dp[i][j] + lvl[i][j]) * (k - j);
		}
	}
	if (len_sum % k)
		throw;
	printf("%lld", len_sum / k);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
	return 0;
}