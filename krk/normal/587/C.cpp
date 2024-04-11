#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;
const int Maxm = 18;
const int lim = 10;

int n, m, q;
vector <int> neigh[Maxn];
vector <int> H[Maxn][Maxm];
int P[Maxn][Maxm], L[Maxn];

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v][0] == u) continue;
		P[u][0] = v; L[u] = L[v] + 1;
		Traverse(u); 
	}
}

void Union(const vector <int> &a, const vector <int> &b, vector <int> &c, int gt = lim)
{
	int i = 0, j = 0;
	while (c.size() < gt && (i < a.size() || j < b.size()))
		if (i < a.size() && (j == b.size() || a[i] < b[j])) { c.push_back(a[i]); i++; }
		else if (j < b.size() && (i == a.size() || b[j] < a[i])) { c.push_back(b[j]); j++; }
		else { c.push_back(a[i]); i++; j++; }
}

int getLCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) a = P[a][i];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i])
			a = P[a][i], b = P[b][i];
	return P[a][0];
}

void Solve(int v, int hm, int a, vector <int> &res)
{
	vector <int> tmp;
	for (int i = Maxm - 1; i >= 0; i--)
		if ((1 << i) <= hm) {
			tmp.clear(); 
			Union(res, H[v][i], tmp, a);
			res = tmp;
			hm -= 1 << i; v = P[v][i];
		}
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= m; i++) {
		int v; scanf("%d", &v);
		if (H[v][0].size() < lim) H[v][0].push_back(i);
	}
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++) {
			P[i][j] = P[P[i][j - 1]][j - 1];
			Union(H[i][j - 1], H[P[i][j - 1]][j - 1], H[i][j]);
		}
	while (q--) {
		int v, u, a; scanf("%d %d %d", &v, &u, &a);
		int lca = getLCA(v, u);
		vector <int> va, vb, vc;
		Solve(v, L[v] - L[lca] + 1, a, va);
		Solve(u, L[u] - L[lca] + 1, a, vb);
		Union(va, vb, vc, a);
		printf("%d", vc.size());
		for (int i = 0; i < vc.size(); i++)
			printf(" %d", vc[i]);
		printf("\n");
	}
	return 0;
}