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

const int Maxn = 200005;
const int Maxm = 20;

int n;
int par[Maxn];
vector <int> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm];
int res, a, b;

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
		if (L[a] - (1 << i) >= L[b]) a = P[a][i];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i]) a = P[a][i], b = P[b][i];
	return P[a][0];
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &par[i]);
		neigh[par[i]].push_back(i);
	}
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	a = b = 1;
	for (int i = 2; i <= n; i++) {
		int o1 = L[a] + L[i] - 2 * L[getLCA(a, i)];
		int o2 = L[b] + L[i] - 2 * L[getLCA(b, i)];
		if (o1 > res || o2 > res)
			if (o1 >= o2) { res = o1; b = i; }
			else { res = o2; a = i; }
		printf("%d%c", res, i + 1 <= n? ' ': '\n');
	}
	return 0;
}