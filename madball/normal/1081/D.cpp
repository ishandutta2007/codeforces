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
#include <random>

using namespace std;

typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n)  for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

struct DSU
{
	vector<int> par;
	vector<int> cnt;
	DSU(int n) : par(n), cnt(n, 0)
	{
		For(i, n)
			par[i] = i;
	}
	int getpar(int a)
	{
		if (par[a] == a)
			return a;
		return par[a] = getpar(par[a]);
	}
	bool merge(int a, int b)
	{
		a = getpar(a);
		b = getpar(b);
		if (a == b)
			return false;
		par[a] = b;
		cnt[b] += cnt[a];
		return true;
	}
};

struct Edge
{
	int u, v, c;
	Edge() {}
	Edge(int u, int v, int c): u(u), v(v), c(c) {}
	bool operator < (const Edge& e) const
	{
		return c < e.c;
	}
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	DSU dsu(n);
	vector<int> chosen(k);
	For(i, k)
	{
		cin >> chosen[i];
		--chosen[i];
		dsu.cnt[chosen[i]]++;
	}
	vector<Edge> edges;
	For(i, m)
	{
		int u, v, c;
		cin >> u >> v >> c;
		--u;
		--v;
		edges.emplace_back(u, v, c);
	}
	sort(all(edges));
	for (auto e : edges)
	{
		dsu.merge(e.u, e.v);
		if (dsu.cnt[dsu.getpar(e.u)] == k)
		{
			For(i, k)
				cout << e.c << ' ';
			return;
		}
	}
	throw;
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