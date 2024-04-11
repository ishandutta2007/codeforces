#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int n, m;
int X[Maxn], Y[Maxn], Z[Maxn];
bool bridge[Maxn];
int a, b;
vector <ii> neigh[Maxn];
int cur, tim[Maxn], low[Maxn];
int par[Maxn], siz[Maxn], has[Maxn];
vector <ii> sneigh[Maxn];

void Traverse(int v, int par = -1)
{
	tim[v] = low[v] = ++cur;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.second == par) continue;
		if (!tim[u.first]) {
			Traverse(u.first, u.second);
			low[v] = min(low[v], low[u.first]);
			if (low[u.first] == tim[u.first]) bridge[u.second] = true;
		} else low[v] = min(low[v], tim[u.first]);
	}
}

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b, bool add = false)
{
	a = getPar(a), b = getPar(b);
	if (a == b) { has[a] |= add; return; }
	if (siz[a] >= siz[b]) { siz[a] += siz[b]; par[b] = a; has[a] |= has[b]; has[a] |= add; }
	else { siz[b] += siz[a]; par[a] = b; has[b] |= has[a]; has[b] |= add; }
}

bool Solve(int v, bool h, int par = -1)
{
	if (v == b) return h;
	for (int i = 0; i < sneigh[v].size(); i++) {
		ii u = sneigh[v][i];
		if (u.first == par) continue;
		if (Solve(u.first, (h || has[u.first] || u.second), v)) return true;
	}
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &X[i], &Y[i], &Z[i]);
		neigh[X[i]].push_back(ii(Y[i], i));
		neigh[Y[i]].push_back(ii(X[i], i));
	}
	scanf("%d %d", &a, &b);
	Traverse(1);
	for (int i = 1; i <= n; i++)
		par[i] = i, siz[i] = 1;
	for (int i = 0; i < m; i++)
		if (!bridge[i]) unionSet(X[i], Y[i], Z[i]);
	for (int i = 0; i < m; i++)
		if (bridge[i]) {
			X[i] = getPar(X[i]), Y[i] = getPar(Y[i]);
			sneigh[X[i]].push_back(ii(Y[i], Z[i]));
			sneigh[Y[i]].push_back(ii(X[i], Z[i]));
		}
	a = getPar(a), b = getPar(b);
	printf("%s\n", Solve(a, has[a])? "YES": "NO");
	return 0;
}