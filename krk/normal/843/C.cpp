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
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 200005;

int n;
vector <int> neigh[Maxn];
vector <int> roots;
int cnt[Maxn];
bool centr[Maxn];
vector <iii> res;

void Traverse(int v, int p)
{
	cnt[v] = 1;
	bool ok = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
		if (cnt[u] > n / 2) ok = false;
		cnt[v] += cnt[u];
	}
	if (n - cnt[v] > n / 2) ok = false;
	centr[v] = ok;
	if (ok) roots.push_back(v);
}

void Count(int v, int p)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p || centr[u]) continue;
		Count(u, v); cnt[v] += cnt[u];
	}
}

int Get(int v, int p, int lim)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p || centr[u]) continue;
		if (cnt[u] > lim) return Get(u, v, lim);
	}
	return v;
}

int getCentroid(int v)
{
	Count(v, 0);
	return Get(v, 0, cnt[v] / 2);
}

void Solve(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (centr[u]) continue;
		int c = getCentroid(u); centr[c] = true;
		res.push_back(iii(v, ii(u, c)));
		Solve(c);
	}
}

void Solve(int v, int p, int root, int c, int &lst)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Solve(u, v, root, c, lst);
	}
	res.push_back(iii(root, ii(lst, v))); lst = v;
	if (v != c) res.push_back(iii(v, ii(p, c)));
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1, 0);
	for (int i = 0; i < roots.size(); i++)
		for (int j = 0; j < neigh[roots[i]].size(); j++) {
			int v = neigh[roots[i]][j];
			int lst = v;
			if (!centr[v]) Solve(v, roots[i], roots[i], v, lst);
		}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d %d\n", res[i].first, res[i].second.first, res[i].second.second);
	return 0;
}