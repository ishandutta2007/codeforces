#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;
const int Maxm = 21;

int n;
vector <int> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm];
int m;
int pl[Maxn], mn[Maxn];
int tot[Maxn];
map <int, int> M[Maxn];
map <ii, int> M2[Maxn];
ll res;

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v][0] == u) continue;
		P[u][0] = v;
		L[u] = L[v] + 1;
		Traverse(u);
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

int getLst(int a, int b)
{
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) > L[b])
			a = P[a][i];
	return a;
}

int Solve(int v)
{
	int cur = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v][0] == u) continue;
		int got = Solve(u) - mn[u];
		res += ll(got) * (tot[v] - M[v][u]);
		cur += got;
	}
	res += ll(pl[v]) * tot[v];
	cur += pl[v];
	res += ll(tot[v]) * (tot[v] - 1) / 2;
	for (auto it: M[v])
		res -= ll(it.second) * (it.second - 1) / 2;
	for (auto it: M2[v])
		res += ll(it.second) * (it.second - 1) / 2; 
	return cur;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		int lca = getLCA(a, b);
		if (a == lca)
			if (b == lca) tot[lca]++;
			else {
				int lstb = getLst(b, lca);
				pl[b]++; mn[lstb]++;
				tot[lca]++;
				M[lca][lstb]++;
			}
		else if (b == lca) {
			int lsta = getLst(a, lca);
			pl[a]++; mn[lsta]++;
			tot[lca]++;
			M[lca][lsta]++;
		} else {
			int lsta = getLst(a, lca);
			int lstb = getLst(b, lca);
			pl[a]++; mn[lsta]++;
			pl[b]++; mn[lstb]++;
			tot[lca]++;
			M[lca][lsta]++;
			M[lca][lstb]++;
			if (lsta > lstb) swap(lsta, lstb);
			M2[lca][ii(lsta, lstb)]++;
		}
	}
	Solve(1);
	printf("%I64d\n", res);
    return 0;
}