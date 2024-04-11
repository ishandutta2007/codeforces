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

int n;
vector <int> neigh[2][Maxn];
int L[2][Maxn], P[2][Maxn][Maxm], R[2][Maxn];

void Traverse(int v, int ind)
{
	for (int i = 0; i < neigh[ind][v].size(); i++) {
		int u = neigh[ind][v][i];
		L[ind][u] = L[ind][v] + 1; P[ind][u][0] = v; R[ind][u] = R[ind][v];
		Traverse(u, ind);
	}
}

bool Reach(int v, int u, int ind)
{
	if (L[ind][v] < L[ind][u]) return false;
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[ind][v] - (1 << i) >= L[ind][u])
			v = P[ind][v][i];
	return v == u;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int par, typ; scanf("%d %d", &par, &typ);
		if (typ == 0) neigh[0][par].push_back(i);
		else if (typ == 1) neigh[1][par].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if (R[0][i] == 0) { R[0][i] = i; Traverse(i, 0); }
		if (R[1][i] == 0) { R[1][i] = i; Traverse(i, 1); }
	}
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++) {
			P[0][i][j] = P[0][P[0][i][j - 1]][j - 1];
			P[1][i][j] = P[1][P[1][i][j - 1]][j - 1];
		}
	int q; scanf("%d", &q);
	while (q--) {
		int typ, a, b; scanf("%d %d %d", &typ, &a, &b);
		if (a == b) { printf("NO\n"); continue; }
		if (typ == 1) printf("%s\n", Reach(b, a, 0)? "YES": "NO");
		else printf("%s\n", !Reach(a, b, 0) && (Reach(b, R[0][a], 1) || Reach(a, R[1][b], 0))? "YES": "NO");
	}
	return 0;
}