#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxm = 200001;

int n;
int a[Maxm];
int par[Maxm], siz[Maxm];
ll cur;
vector <int> V[Maxm];
vector <ii> E[Maxm];
ll res[Maxm];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (siz[a] < siz[b]) swap(a, b);
	cur -= ll(siz[a]) * (siz[a] + 1) / 2;
	cur -= ll(siz[b]) * (siz[b] + 1) / 2;
	siz[a] += siz[b]; par[b] = a;
	cur += ll(siz[a]) * (siz[a] + 1) / 2;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		V[a[i]].push_back(i);
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v; scanf("%d %d", &u, &v);
		E[gcd(a[u], a[v])].push_back(ii(u, v));
	}
	for (int i = Maxm - 1; i > 0; i--) {
		cur = 0;
		for (int j = i; j < Maxm; j += i) {
			for (int k = 0; k < V[j].size(); k++) {
				int v = V[j][k];
				par[v] = v; siz[v] = 1;
				cur++;
			}
			if (j > i) res[i] -= res[j];
		}
		for (int j = i; j < Maxm; j += i)
			for (int k = 0; k < E[j].size(); k++) {
				ii& p = E[j][k];
				unionSet(p.first, p.second);
			}
		res[i] += cur;
	}
	for (int i = 1; i < Maxm; i++) if (res[i] > 0)
		printf("%d %I64d\n", i, res[i]);
	return 0;
}