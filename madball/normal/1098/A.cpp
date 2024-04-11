#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

#ifdef LOCAL
#pragma comment(linker, "/STACK:16777216")
#endif

const int MAXN = (int)1e5 + 10;
const int INF = (int)1e9 + 7;
int par[MAXN];
int lvl[MAXN];
vector<int> graph[MAXN];
int val[MAXN];

void solve()
{
	int n;
	cin >> n;
	par[0] = -1;
	for (int i = 1; i < n; ++i)
	{
		cin >> par[i];
		--par[i];
		graph[i].push_back(par[i]);
		graph[par[i]].push_back(i);
	}
	For(i, n)
		cin >> val[i];
	For(i, n)
	{
		if (val[i] >= 0)
			continue;
		val[i] = INF;
		for (auto e : graph[i])
			if (e != par[i])
				val[i] = min(val[i], val[e]);
		if (val[i] == INF)
			val[i] = val[par[i]];
		val[i] = max(val[i], val[par[i]]);
	}
	lint res = val[0];
	for (int i = 1; i < n; ++i)
	{
		if (val[i] < val[par[i]])
		{
			cout << -1;
			return;
		}
		res += val[i] - val[par[i]];
	}
	cout << res;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}