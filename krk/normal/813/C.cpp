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

int n, x;
int bobL;
vector <int> neigh[Maxn];
int L[Maxn], all[Maxn];
bool bob[Maxn];
int res;

void Traverse(int v, int p = 0)
{
	if (x == v) { bobL = L[v]; bob[v] = true; }
	all[v] = L[v];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		L[u] = L[v] + 1; Traverse(u, v);
		all[v] = max(all[v], all[u]); bob[v] |= bob[u];
	}
	if (bob[v] && bobL - L[v] < L[v]) res = max(res, all[v]);
}

int main()
{
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	printf("%d\n", 2 * res);
	return 0;
}