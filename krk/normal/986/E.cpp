#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int Maxk = 19;
const int Maxm = 10000005;
const int mod = 1000000007;

vector <int> primes;
int mn[Maxm];
int n;
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int L[Maxn], P[Maxn][Maxk];
int q;
vector <ii> vert[Maxm], quer[Maxm];
int U[Maxn], V[Maxn], LCA[Maxn];
int BIT[Maxn];
int res[Maxn];

void Record(int a, int ind, vector <ii> V[])
{
	while (a > 1) {
		int val = mn[a];
		int cnt = 0;
		while (mn[a] == val) {
			a /= val; cnt++;
		}
		V[val].push_back(ii(cnt, ind));
	}
}

void Traverse(int v)
{
	lef[v] = ++cur;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v][0] == u) continue;
		L[u] = L[v] + 1; P[u][0] = v;
		Traverse(u);
	}
	rig[v] = cur;
}

void Clear(int ind)
{
	for (int i = ind; i <= n; i += i & -i)
		BIT[i] = 0;
}

void Add(int ind, int val)
{
	for (int i = ind; i <= n; i += i & -i)
		BIT[i] += val;
}

int Get(int ind)
{
	int res = 0;
	for (int i = ind; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int getLCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxk - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b])
			a = P[a][i];
	if (a == b) return a;
	for (int i = Maxk - 1; i >= 0; i--)
		if (P[a][i] != P[b][i])
			a = P[a][i], b = P[b][i];
	return P[a][0];
}

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int main()
{
	for (int i = 2; i < Maxm; i++) {
		if (mn[i] == 0) { mn[i] = i; primes.push_back(i); }
		for (int j = 0; j < primes.size() && i * primes[j] < Maxm; j++) {
			mn[i * primes[j]] = primes[j];
			if (i % primes[j] == 0) break;
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		Record(a, i, vert);
	}
	Traverse(1);
	for (int j = 1; j < Maxk; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int a; scanf("%d %d %d", &U[i], &V[i], &a);
		Record(a, i, quer);
		res[i] = 1;
		LCA[i] = getLCA(U[i], V[i]);
	}
	for (int i = 0; i < primes.size(); i++) {
		int p = primes[i];
		if (quer[p].empty()) continue;
		sort(vert[p].begin(), vert[p].end());
		sort(quer[p].begin(), quer[p].end());
		int pnt = 0, cur = 0;
		for (int i = 0; i < quer[p].size(); i++) {
			int nd = quer[p][i].first;
			int ind = quer[p][i].second;
			while (cur < nd) {
				while (pnt < vert[p].size() && vert[p][pnt].first <= cur) pnt++;
				for (int i = pnt; i < vert[p].size(); i++) {
					int v = vert[p][i].second;
					Add(lef[v], 1); Add(rig[v] + 1, -1);
				}
				cur++;
			}
			int a = U[ind], b = V[ind];
			int lca = LCA[ind];
			int cnt = Get(lef[a]) + Get(lef[b]) - Get(lef[lca]) - Get(lef[P[lca][0]]);
			res[ind] = ll(res[ind]) * toPower(p, cnt) % mod;
		}
		for (int j = 0; j < vert[p].size(); j++) {
			int v = vert[p][j].second;
			Clear(lef[v]); Clear(rig[v] + 1);
		}
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", res[i]);
	return 0;
}