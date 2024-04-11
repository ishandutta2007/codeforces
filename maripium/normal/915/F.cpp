#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1000005;

int n;
int a[Maxn];
vector <int> neigh[Maxn];
ii seq[Maxn];
int par[Maxn], siz[Maxn];
bool tk[Maxn];
ll res;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b, ll val)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (siz[a] < siz[b]) swap(a, b);
	res += val * ll(siz[a]) * siz[b];
	siz[a] += siz[b]; par[b] = a;
}

void Solve()
{
	fill(tk, tk + n + 1, false);
	for (int i = 1; i <= n; i++) {
		int v = seq[i].second;
		tk[v] = true; par[v] = v; siz[v] = 1;
		for (int j = 0; j < neigh[v].size(); j++) {
			int u = neigh[v][j];
			if (tk[u]) unionSet(v, u, seq[i].first);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		seq[i] = ii(a[i], i);
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	sort(seq + 1, seq + n + 1);
	Solve();
	for (int i = 1; i <= n; i++) seq[i].first = -seq[i].first;
	sort(seq + 1, seq + n + 1);
	Solve();
	cout << res << endl;
	return 0;
}