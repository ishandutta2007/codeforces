#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef long long ll;

const int Maxn = 100005;
const int Maxm = 20;

int n, m;
vector <iii> E;
int par[Maxn], siz[Maxn];
vector <ii> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm], M[Maxn][Maxm];

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
		P[u.first][0] = v; L[u.first] = L[v] + 1;
		M[u.first][0] = u.second;
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
	int res = 0;
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) {
			res = max(res, M[a][i]);
			a = P[a][i];
		}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		par[i] = i, siz[i] = 1;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		E.push_back(iii(c, ii(a, b)));
	}
	sort(E.begin(), E.end());
	ll cost = 0;
	for (int i = 0; i < E.size(); i++) {
		int a = E[i].second.first, b = E[i].second.second, c = E[i].first;
		if (unionSet(a, b)) {
			cost += c;
			neigh[a].push_back(ii(b, c));
			neigh[b].push_back(ii(a, c));
		}
	}
	for (int i = 1; i <= n; i++) if (getPar(i) == i)
		Traverse(i);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++) {
			int par = P[i][j - 1];
			P[i][j] = P[par][j - 1];
			M[i][j] = max(M[i][j - 1], M[par][j - 1]);
		}
	int q; scanf("%d", &q);
	while (q--) {
		int a, b; scanf("%d %d", &a, &b);
		if (getPar(a) == getPar(b))
			if (siz[getPar(a)] == n) {
				int lca = getLCA(a, b);
				printf("%I64d\n", cost - ll(max(getMax(a, lca), getMax(b, lca))));
			} else printf("-1\n");
		else if (siz[getPar(a)] + siz[getPar(b)] == n)
				printf("%I64d\n", cost);
			else printf("-1\n");
	}
    return 0;
}