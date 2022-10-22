#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Maxm = 22;
const int Inf = 1000000000;

int n, k;
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int P[Maxn][Maxm], L[Maxn];
bool tk[Maxn];
set <ii> S;

void Traverse(int v)
{
	lef[v] = ++cur;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v][0] == u) continue;
		P[u][0] = v; L[u] = L[v] + 1;
		Traverse(u);
	}
	rig[v] = cur;
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

int getDist(int a, int b) { return L[a] - L[getLCA(a, b)]; }

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(n);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	int lft = n - k - 1; tk[n] = true;
	S.insert(ii(lef[n], n));
	for (int i = n - 1; i >= 1; i--) if (!tk[i]) {
		set <ii>::iterator it = S.lower_bound(ii(lef[i], 0));
		int dist = Inf;
		if (it != S.begin()) dist = min(dist, getDist(i, it->second));
		if (it != S.begin()) {
			it--; dist = min(dist, getDist(i, it->second));
		}
		if (dist <= lft) {
			int v = i;
			while (!tk[v]) {
				tk[v] = true; lft--;
				S.insert(ii(lef[v], v));
				v = P[v][0];
			}
		}
	}
	bool pr = false;
	for (int i = 1; i <= n; i++) if (!tk[i]) {
		if (pr) printf(" ");
		else pr = true;
		printf("%d", i);
	}
	printf("\n");
	return 0;
}