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

const int Maxn = 100005;
const int Maxm = 20;

int n, q;
vector <int> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm];

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		L[u] = L[v] + 1; P[u][0] = v;
		Traverse(u);
	}
}

int getLCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b])
			a = P[a][i];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i])
			a = P[a][i], b = P[b][i];
	return P[a][0];
}

int Solve(int a, int b, int c)
{
	int lca1 = getLCA(a, b), lca2 = getLCA(a, c);
	if (L[lca1] < L[lca2]) lca1 = lca2;
	int dist = L[a] - L[lca1] + 1;
	int lca3 = getLCA(b, c);
	if (L[lca3] > L[lca1]) dist += L[lca3] - L[lca1];
	return dist;
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		neigh[p].push_back(i);
	}
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	while (q--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		int res = Solve(a, b, c);
		res = max(res, Solve(b, a, c));
		res = max(res, Solve(c, a, b));
		printf("%d\n", res);
	}
	return 0;
}