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

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 500005;
const int Maxm = 21;

int n;
int root;
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int L[Maxn], P[Maxn][Maxm];
vector <int> seq[Maxn];
vector <int> tneigh[Maxn];
ll res1[Maxn], res2[Maxn], res3[Maxn];

void Traverse(int v)
{
	lef[v] = ++cur;
	seq[L[v]].push_back(v);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		P[u][0] = v; L[u] = L[v] + 1;
		Traverse(u);
	}
	rig[v] = cur;
}

int getLCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) a = P[a][i];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i]) a = P[a][i], b = P[b][i];
	return P[a][0];
}

void Collect(int v, int need)
{
	res1[v] = L[v] == need? 1: 0;
	for (int i = 0; i < tneigh[v].size(); i++) {
		int u = tneigh[v][i];
		Collect(u, need);
		res1[v] += res1[u];
	}
}

void Compute(int v, int need)
{
	if (L[v] != need) res2[v] += res1[v];
	else res3[v] += res2[v];
	for (int i = 0; i < tneigh[v].size(); i++) {
		int u = tneigh[v][i];
		res2[u] += res2[v] + ll(L[u] - L[v] - 1) * res1[u];
		Compute(u, need);
	}
}

void Solve(int lvl)
{
	vector <ii> my;
	for (int i = 0; i < seq[lvl].size(); i++)
		my.push_back(ii(lef[seq[lvl][i]], seq[lvl][i]));
	for (int i = 1; i < seq[lvl].size(); i++) {
		int g = getLCA(seq[lvl][i - 1], seq[lvl][i]);
		my.push_back(ii(lef[g], g));
	}
	sort(my.begin(), my.end()); my.erase(unique(my.begin(), my.end()), my.end());
	vector <int> S;
	int root = 0;
	for (int i = 0; i < my.size(); i++) {
		while (!S.empty() && rig[S.back()] < my[i].first) S.pop_back();
		if (S.empty()) root = my[i].second;
		else tneigh[S.back()].push_back(my[i].second);
		S.push_back(my[i].second);
	}
	if (root) {
		Collect(root, lvl);
		res2[root] += ll(L[root] - 1) * res1[root];
		Compute(root, lvl);
	}
	for (int i = 0; i < my.size(); i++) {
		res1[my[i].second] = res2[my[i].second] = 0;
		tneigh[my[i].second].clear();
	}
}

void Finalize(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		res3[u] += res3[v];
		Finalize(u);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int p; scanf("%d", &p);
		if (p == 0) root = i;
		else neigh[p].push_back(i);
	}
	L[root] = 1; Traverse(root);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	for (int i = 0; i <= n; i++)
		Solve(i);
	Finalize(root);
	for (int i = 1; i <= n; i++)
		printf("%I64d%c", res3[i], i + 1 <= n? ' ': '\n');
	return 0;
}