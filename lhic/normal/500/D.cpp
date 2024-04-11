#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <bitset>


using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 200000;

int was[MAXN];

int sz[MAXN];

ll oc[MAXN];
int aa[MAXN];
int bb[MAXN];
int ww[MAXN];

vector<pair<int, int> > eds[MAXN];

int n;
int q;

int dfs(int v)
{
	was[v] = 1;
	sz[v] = 1;
	for (int i = 0; i < eds[v].size(); ++i)
	{
		int u = eds[v][i].first;
		if (!was[u])
			sz[v] += dfs(u);
	}
	return sz[v];
}


void dfs2(int v)
{
	was[v] = 1;
	
	for (int i = 0; i < eds[v].size(); ++i)
	{
		int u = eds[v][i].first;
		int x = eds[v][i].second;
		if (was[u])
			continue;
		oc[x] = (ll)sz[u] * (ll)(n - sz[u]);
		dfs2(u);
	}
}



int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		--a;
		--b;
		eds[a].push_back({b, i});
		eds[b].push_back({a, i});
		aa[i] = a;
		bb[i] = b;
		ww[i] = w;
	}
	
	
	dfs(0);
	memset(was, 0, sizeof(was[0]) * n);
	
	dfs2(0);
	
	ll ans = 0;
	for (int i = 0; i < n - 1; ++i)
		ans += oc[i] * ww[i];
	
	scanf("%d", &q);
	
	cout.setf(ios::fixed);
	cout.precision(10);
	for (int i = 0; i < q; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		ans -= oc[a] * (ww[a] - b);
		ww[a] = b;
		
		cout << 6 * ans / (((ld)n) * (n - 1)) << "\n";	
	}
	
	
	
	
	
	return 0;
}