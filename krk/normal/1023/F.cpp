#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef long long ll;

const int Maxn = 500005;
const int Maxm = 21;
const int Inf = 1000000007;

int n, k, m;
int par[Maxn], siz[Maxn];
vector <iii> E;
vector <ii> neigh[Maxn];
int P[Maxn][Maxm], L[Maxn], C[Maxn];
int my[Maxn][Maxm];
bool inf;
ll res;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return false;
	if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b]; par[b] = a;
	return true;
}

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (P[v][0] == u.first) continue;
		P[u.first][0] = v; L[u.first] = L[v] + 1; C[u.first] = u.second;
		Traverse(u.first);
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

void Set(int a, int b, int val)
{
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) {
			my[a][i] = min(my[a][i], val);
			a = P[a][i];
		}
}

int main()
{
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= n; i++)
		par[i] = i, siz[i] = 1;
	for (int i = 0; i < k; i++) {
		int ga, gb; scanf("%d %d", &ga, &gb);
		E.push_back(iii(0, ii(ga, gb)));
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		E.push_back(iii(c, ii(a, b)));
	}
	sort(E.begin(), E.end());
	for (int i = 0; i < E.size(); i++) {
		int a = E[i].second.first, b = E[i].second.second;
		int c = E[i].first;
		if (unionSet(a, b)) {
			neigh[a].push_back(ii(b, c));
			neigh[b].push_back(ii(a, c));
		}
	}
	for (int i = 1; i <= n; i++) if (getPar(i) == i) {
		C[i] = 1;
		Traverse(i);
	}
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	fill((int*)my, (int*)my + Maxn * Maxm, Inf);
	for (int i = 0; i < E.size(); i++) if (E[i].first) {
		int a = E[i].second.first, b = E[i].second.second;
		int lca = getLCA(a, b);
		Set(a, lca, E[i].first);
		Set(b, lca, E[i].first);
	}
	for (int j = Maxm - 1; j > 0; j--)
		for (int i = 1; i <= n; i++) {
			my[i][j - 1] = min(my[i][j - 1], my[i][j]);
			my[P[i][j - 1]][j - 1] = min(my[P[i][j - 1]][j - 1], my[i][j]);
		}
	for (int i = 1; i <= n; i++)
		if (C[i] == 0)
			if (my[i][0] >= Inf) inf = true;
			else res += my[i][0];
	if (inf) printf("-1\n");
	else printf("%I64d\n", res);
	return 0;
}