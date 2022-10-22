#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 21;
const int Inf = 1000000007;

int siz[Maxn], par[Maxn];
int n, m;
int w[Maxn], c[Maxn], a[Maxn], b[Maxn];
vector <ii> E;
vector <ii> neigh[Maxn];
int P[Maxn][Maxm], M[Maxn][Maxm], L[Maxn];
ll sum;
ll best;
int bi;
int S;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return false;
	if (siz[a] >= siz[b]) { siz[a] += siz[b]; par[b] = a; }
	else { siz[b] += siz[a]; par[a] = b; }
	return true;
}

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (P[v][0] == u.first) continue;
		P[u.first][0] = v; M[u.first][0] = u.second; L[u.first] = L[v] + 1;
		Traverse(u.first);
	}
}

int getMax(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	int mx = 0;
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) {
			mx = max(mx, M[a][i]);
			a = P[a][i];
		}
	if (a == b) return mx;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i]) {
			mx = max(mx, max(M[a][i], M[b][i]));
			a = P[a][i], b = P[b][i];
		}
	mx = max(mx, max(M[a][0], M[b][0]));
	return mx;
}

void Print()
{
	printf("%I64d\n", best);
	for (int i = 1; i <= n; i++) {
		siz[i] = 1; par[i] = i;
	}
	if (bi) {
		unionSet(a[bi], b[bi]);
		printf("%d %d\n", bi, w[bi] - S / c[bi]);
	}
	for (int i = 0; i < E.size(); i++) {
		int ind = E[i].second;
		if (unionSet(a[ind], b[ind]))
			printf("%d %d\n", ind, w[ind]);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		siz[i] = 1; par[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
		E.push_back(ii(w[i], i));
	}
	for (int i = 1; i <= m; i++)
		scanf("%d", &c[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d %d", &a[i], &b[i]);
	sort(E.begin(), E.end());
	int mn = Inf;
	for (int i = 0; i < E.size(); i++) {
		int ind = E[i].second;
		if (unionSet(a[ind], b[ind])) {
			neigh[a[ind]].push_back(ii(b[ind], w[ind]));
			neigh[b[ind]].push_back(ii(a[ind], w[ind]));
			sum += w[ind]; 
			if (c[ind] < mn) { mn = c[ind]; bi = ind; }
		}
	}
	scanf("%d", &S); sum -= S / mn;
	best = sum;
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++) {
			P[i][j] = P[P[i][j - 1]][j - 1];
			M[i][j] = max(M[i][j - 1], M[P[i][j - 1]][j - 1]);
		}
	for (int i = 1; i <= m; i++) if (c[i] < mn) {
		ll cand = sum + ll(S / mn) - ll(S / c[i]) - ll(getMax(a[i], b[i])) + ll(w[i]);
		if (cand < best) { best = cand; bi = i; }
	}
	Print();
	return 0;
}