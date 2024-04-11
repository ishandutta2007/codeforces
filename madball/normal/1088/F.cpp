#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <ctime>
#include <functional>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <string>

#pragma comment(linker, "/STACK:67108864")

using namespace std;

typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n)  for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

const int MAXN = (int)5e5 + 10;
const int LOG = 20;
vector<int> graph[MAXN];
lint weight[MAXN];
int up[LOG][MAXN];

void dfs(int v, int from = -1)
{
	up[0][v] = from == -1 ? v : from;
	for (auto e : graph[v])
		if (e != from)
			dfs(e, v);
}

void solve() {
	int n;
	cin >> n;
	int root = 0;
	lint res = 0;
	For(i, n)
	{
		weight[i] = 1000000000 - i;
		cin >> weight[i];
		res += weight[i];
		if (weight[i] < weight[root])
			root = i;
	}
	res -= weight[root];
	For(i, n - 1)
	{
		int a, b;
		a = i + 1;
		b = n;
		cin >> a >> b;
		--a;
		--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(root);
	For(l, LOG - 1) For(i, n)
		up[l + 1][i] = up[l][up[l][i]];
	for (int i = 0; i < n; ++i)
	{
		if (i == root)
			continue;
		lint cur = weight[up[0][i]];
		For(l, LOG)
			cur = min(cur, weight[up[l][i]] * (l + 1));
		res += cur;
	}
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}