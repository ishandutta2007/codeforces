#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, ii> iiii;

const int Maxn = 200005;
const int Maxm = 20;
const int Inf = 2000000007;

int n, m;
int a[Maxn], b[Maxn], c[Maxn];
vector <iiii> E;
int par[Maxn], siz[Maxn];
bool tk[Maxn];
vector <ii> neigh[Maxn];
int L[Maxn], W[Maxn], P[Maxn][Maxm];
int M[Maxn][Maxm];
int best[Maxn][Maxm];
int res[Maxn];

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
		if (u.first == P[v][0]) continue;
		L[u.first] = L[v] + 1;
		W[u.first] = u.second;
		P[u.first][0] = v;
		M[u.first][0] = c[u.second];
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

int getMax(int a, int b)
{
	int mx = 0;
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) {
			mx = max(mx, M[a][i]);
			a = P[a][i];
		}
	return mx;
}

void Update(int a, int b, int val)
{
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) {
			best[a][i] = min(best[a][i], val);
			a = P[a][i];
		}
}

void finalTraverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == P[v][0]) continue;
		res[u.second] = best[u.first][0] >= Inf? -1: best[u.first][0] - 1;
		finalTraverse(u.first);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		E.push_back(iiii(ii(c[i], i), ii(a[i], b[i])));
	}
	for (int i = 1; i <= n; i++)
		par[i] = i, siz[i] = 1;
	sort(E.begin(), E.end());
	for (int i = 0; i < E.size(); i++) {
		int id = E[i].first.second;
		int a = E[i].second.first;
		int b = E[i].second.second;
		tk[id] = unionSet(a, b);
		if (tk[id]) {
			neigh[a].push_back(ii(b, id));
			neigh[b].push_back(ii(a, id));
		}
	}
	Traverse(1);
	for (int i = 1; i <= n; i++)
		best[i][0] = Inf;
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++) {
			int p = P[i][j - 1];
			P[i][j] = P[p][j - 1];
			M[i][j] = max(M[i][j - 1], M[p][j - 1]);
			best[i][j] = Inf;
		}
	for (int i = 0; i < m; i++)
		if (!tk[i]) {
			int lca = getLCA(a[i], b[i]);
			res[i] = max(getMax(a[i], lca), getMax(b[i], lca)) - 1;
			Update(a[i], lca, c[i]);
			Update(b[i], lca, c[i]);
		}
	for (int j = Maxm - 1; j > 0; j--)
		for (int i = 1; i <= n; i++) {
			int p = P[i][j - 1];
			best[i][j - 1] = min(best[i][j - 1], best[i][j]);
			best[p][j - 1] = min(best[p][j - 1], best[i][j]);
		}
	finalTraverse(1);
	for (int i = 0; i < m; i++)
		printf("%d%c", res[i], i + 1 < m? ' ': '\n');
    return 0;
}