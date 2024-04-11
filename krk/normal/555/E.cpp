#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 20;

int n, m, q;
vector <ii> neigh[Maxn];
int A[Maxn], B[Maxn];
int s[Maxn], d[Maxn];
int cur, col[Maxn];
int tim[Maxn], low[Maxn];
bool er[Maxn];
vector <int> gneigh[Maxn];
int P[Maxn][Maxm], L[Maxn];
bool up[Maxn][Maxm], dwn[Maxn][Maxm];

void Fill(int v, int c)
{
	if (col[v]) return;
	col[v] = c;
	for (int i = 0; i < neigh[v].size(); i++) if (!er[neigh[v][i].second])
		Fill(neigh[v][i].first, c);
}

void Traverse(int v, int p)
{
	tim[v] = low[v] = ++cur;
	for (int i = 0; i < neigh[v].size(); i++) {
		if (neigh[v][i].second == p) continue;
		int u = neigh[v][i].first;
		if (!tim[u]) {
			Traverse(u, neigh[v][i].second);
			low[v] = min(low[v], low[u]);
		} else low[v] = min(low[v], tim[u]);
		if (tim[v] < low[u]) er[neigh[v][i].second] = true;
	}
}

void buildTree(int v, int p)
{
	for (int i = 0; i < gneigh[v].size(); i++) {
		int u = gneigh[v][i];
		if (u == p) continue;
		P[u][0] = v; L[u] = L[v] + 1;
		buildTree(u, v);
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

void Update(int a, int b, bool wh[][Maxm])
{
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) {
			wh[a][i] = true;
			a = P[a][i];
		}
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		A[i] = a; B[i] = b;
		neigh[a].push_back(ii(b, i));
		neigh[b].push_back(ii(a, i));
	}
	for (int i = 1; i <= n; i++) if (!col[i]) {
		cur++;
		Fill(i, cur);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &s[i], &d[i]);
		if (col[s[i]] != col[d[i]]) {
			printf("No\n");
			return 0;
		}
	}
	cur = 0;
	for (int i = 1; i <= n; i++) if (!tim[i])
		Traverse(i, -1);
	fill(col, col + n + 1, 0);
	cur = 0;
	for (int i = 1; i <= n; i++) if (!col[i]) {
		cur++;
		Fill(i, cur);
	}
	for (int i = 0; i < m; i++) if (er[i]) {
		int a = col[A[i]], b = col[B[i]];
		gneigh[a].push_back(b);
		gneigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) if (L[i] == 0) {
		L[i] = 1;
		buildTree(i, 0);
	}
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	for (int i = 0; i < q; i++) {
		int A = col[s[i]], B = col[d[i]];
		if (A == B) continue;
		int lca = getLCA(A, B);
		Update(A, lca, up);
		Update(B, lca, dwn);
	}
	for (int j = Maxm - 1; j > 0; j--)
		for (int i = 1; i <= n; i++) {
			if (up[i][j])
				up[i][j - 1] = up[P[i][j - 1]][j - 1] = true;
			if (dwn[i][j])
				dwn[i][j - 1] = dwn[P[i][j - 1]][j - 1] = true;
		}
	for (int i = 1; i <= n; i++)
		if (up[i][0] && dwn[i][0]) {
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
    return 0;
}