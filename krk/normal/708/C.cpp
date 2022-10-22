#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 400005;

int n;
vector <int> neigh[Maxn];
int cnt[Maxn];
int root;
multiset <int> my[Maxn];
int par[Maxn];
int res[Maxn];
multiset <int> S;

int Get(int v, int p = 0)
{
	cnt[v] = 1;
	int mx = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		int cand = Get(u, v);
		if (cand != -1) return cand;
		mx = max(mx, cnt[u]); cnt[v] += cnt[u];
	}
	mx = max(mx, n - cnt[v]);
	if (mx <= n / 2) return v;
	return -1;
}

void Join(int a, int b)
{
	for (multiset <int>::iterator it = my[b].begin(); it != my[b].end(); it++)
		my[a].insert(*it);
	my[b].clear();
}

void Traverse(int v, int p = 0)
{
	cnt[v] = 1;
	par[v] = v;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v); cnt[v] += cnt[u];
		if (v != root) 
			if (my[par[v]].size() <= my[par[u]].size()) { Join(par[u], par[v]); par[v] = par[u]; }
			else { Join(par[v], par[u]); par[u] = par[v]; }
	}
	my[par[v]].insert(cnt[v]);
	if (v != root) S.insert(cnt[v]);
}

void Solve(int v, int p)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Solve(u, v);
	}
	if (n - cnt[v] <= n / 2) res[v] = 1;
	else {
		int lft = n - cnt[v] - n / 2;
		multiset <int>::iterator it = S.lower_bound(lft);
		res[v] = it != S.end() && *it <= n / 2;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	root = Get(1); res[root] = 1; Traverse(root);
	for (int i = 0; i < neigh[root].size(); i++) {
		int v = neigh[root][i];
		for (multiset <int>::iterator it = my[par[v]].begin(); it != my[par[v]].end(); it++) {
			multiset <int>::iterator it2 = S.lower_bound(*it);
			S.erase(it2);
		}
		S.insert(n - cnt[v]);
		Solve(v, root);
		for (multiset <int>::iterator it = my[par[v]].begin(); it != my[par[v]].end(); it++)
			S.insert(*it);
		multiset <int>::iterator it2 = S.lower_bound(n - cnt[v]);
		S.erase(it2);
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}