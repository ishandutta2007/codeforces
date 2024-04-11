#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = (int) 3e5 + 100;
vector <int> g[N];
vector <pair <int, int> > G[N];

map <int, long long> vToMinCost[N];
multiset <long long> costs[N];
long long addToAll[N];

int ansAt[N];

void upd(int id, int v, long long x)
{
	x -= addToAll[id];
	if (vToMinCost[id].count(v) == 0 || vToMinCost[id][v] > x)
	{
		if (vToMinCost[id].count(v) != 0)
			costs[id].erase(costs[id].find(vToMinCost[id][v] ) );
		vToMinCost[id][v] = x;
		costs[id].insert(x);
	}
}

void del(int id, int v)
{
	if (vToMinCost[id].count(v) )
	{
		costs[id].erase(costs[id].find(vToMinCost[id][v] ) );
		vToMinCost[id].erase(v);
	}
}

void solve(int v, int par)
{
	ansAt[v] = v;
	for (auto p : G[v] )
		upd(v, p.first, p.second);
	
	for (int to : g[v] )
	{
		if (to == par) continue;
		solve(to, v);

		int a = ansAt[v], b = ansAt[to];
		if (vToMinCost[a].size() < vToMinCost[b].size() )
			swap(a, b);

		del(a, to);
		del(b, to);
		if (vToMinCost[a].empty() || vToMinCost[b].empty() )
		{
			printf("-1\n");
			exit(0);
		}
//		eprintf("a = %d, b = %d\n", a, b);

		long long mn = *costs[b].begin() + addToAll[b];
		long long mna = *costs[a].begin() + addToAll[a];
		addToAll[a] += mn;
		addToAll[b] += mna;
//		eprintf("mn = %lld, mna = %lld\n", mn, mna);
		for (auto p : vToMinCost[b] )
			upd(a, p.first, p.second + addToAll[b] );
		
		ansAt[v] = a;
	}

//	int id = ansAt[v];
//	eprintf("v = %d, par = %d, id = %d\n", v, par, id);
//	for (auto p : vToMinCost[id] )
//		eprintf("%d %lld\n", p.first, p.second + addToAll[id] );
//	eprintf("\n");
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		G[i].push_back(make_pair(i, 0) );
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		G[a].push_back(make_pair(b, c) );
	}
	solve(0, -1);
	int id = ansAt[0];
	long long ans = *costs[id].begin() + addToAll[id];
	printf("%lld\n", ans);

	return 0;
}