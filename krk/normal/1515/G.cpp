#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;

int n, m;
vector <ii> neigh[Maxn];
int cur, low[Maxn], tim[Maxn];
bool onStack[Maxn];
vector <int> S;
int len, my[Maxn];
ll lab[Maxn], g[Maxn];

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

void SCC(int v)
{
	cur++;
	tim[v] = low[v] = cur;
	S.push_back(v);
	onStack[v] = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		if (!tim[u]) {
			SCC(u);
			low[v] = min(low[v], low[u]);
		} else if (onStack[u])
			low[v] = min(low[v], tim[u]);
	}
	if (low[v] == tim[v]) {
		len++;
		int u;
		do {
			u = S.back(); S.pop_back();
			onStack[u] = false;
			my[u] = len;
		} while (u != v);
	}
}

void Solve(int v, ll mylab, ll myg)
{
	if (lab[v] != -1 && gcd(abs(lab[v] - mylab), gcd(myg, g[v])) == g[v]) return;
	if (lab[v] == -1) lab[v] = mylab;
	g[v] = gcd(abs(lab[v] - mylab), gcd(myg, g[v]));
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		int l = neigh[v][i].second;
		if (my[v] == my[u])
			Solve(u, lab[v] + l, g[v]);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, l; scanf("%d %d %d", &a, &b, &l);
		neigh[a].push_back(ii(b, l));
	}
	for (int i = 1; i <= n; i++) if (!tim[i])
		SCC(i);
	fill(lab, lab + n + 1, -1ll);
	for (int i = 1; i <= n; i++) if (lab[i] == -1)
		Solve(i, lab[i], 0);
	int q; scanf("%d", &q);
	while (q--) {
		int v, s, t; scanf("%d %d %d", &v, &s, &t);
		s = (t - s) % t;
		if (s == 0) printf("YES\n");
		else if (g[v] == 0) printf("NO\n");
		else printf("%s\n", s % gcd(g[v], t) == 0? "YES": "NO");
	}
    return 0;
}