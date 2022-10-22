#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;

int n, m;
vector <ii> E;
int res;
int par[Maxn], siz[Maxn];
vector <int> neigh[Maxn];
vector <int> tneigh[Maxn];
int L[Maxn], P[Maxn];
bool jon[Maxn];
int dp[Maxn];
bool tk[Maxn];

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
		int u = neigh[v][i];
		if (u == P[v]) continue;
		L[u] = L[v] + 1;
		P[u] = v;
		Traverse(u);
	}
}

void Prepare(int v, int p)
{
	dp[v] = 1;
	for (int i = 0; i < tneigh[v].size(); i++) {
		int u = tneigh[v][i];
		if (u == p) continue;
		Prepare(u, v);
		dp[v] += max(1, dp[u] - 1);
	}
}

int Solve(int v, int p, int cur)
{
	cur += dp[v];
	int res = cur;
	for (int i = 0; i < tneigh[v].size(); i++) {
		int u = tneigh[v][i];
		if (u == p) continue;
		res = max(res, Solve(u, v, cur - max(1, dp[u] - 1)));
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		siz[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		if (unionSet(a, b)) {
			neigh[a].push_back(b);
			neigh[b].push_back(a);
		} else E.push_back(ii(a, b));
	}
	res--;
	for (int i = 1; i <= n; i++) if (L[i] == 0) {
		res++;
		Traverse(i);
	}
	for (int i = 0; i < E.size(); i++) {
		int a = E[i].first, b = E[i].second;
		while (a != b)
			if (L[a] > L[b]) { jon[a] = true; a = P[a]; }
			else { jon[b] = true; b = P[b]; }
	}
	for (int i = 1; i <= n; i++) {
		par[i] = i, siz[i] = 1;
	}
	for (int i = 1; i <= n; i++) if (jon[i])
		unionSet(i, P[i]);
	for (int i = 1; i <= n; i++)
		if (L[i] > 0 && !jon[i]) {
			int a = getPar(i), b = getPar(P[i]);
			tneigh[a].push_back(b);
			tneigh[b].push_back(a);
		}
	res += n;
	for (int i = 1; i <= n; i++) if (L[i] == 0) {
		int v = getPar(i);
		tk[v] = true;
		vector <int> seq;
		seq.push_back(v);
		for (int j = 0; j < seq.size(); j++) {
			v = seq[j];
			for (int k = 0; k < tneigh[v].size(); k++) {
				int u = tneigh[v][k];
				if (!tk[u]) {
					tk[u] = true;
					seq.push_back(u);
				}
			}
		}
		int cand = 0;
		for (int j = 0; j < seq.size(); j++) {
			Prepare(seq[j], 0);
			cand = max(cand, Solve(seq[j], 0, 0));
		}
		res -= cand;
	}
	printf("%d\n", res);
    return 0;
}