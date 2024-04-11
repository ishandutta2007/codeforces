#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

typedef long long LL;

typedef pair<int, int> PII;

const int N = 2e5 + 5;

int n, m, k, t[N], p1[N], p2[N];

int a[N], b[N];

bool vis[N];

vector<int> g[N];

priority_queue<PII, vector<PII>, greater<PII> > q;

void dij(int s, int d[]) {
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++) d[i] = 1e9;
	d[s] = 0, q.push(mp(0, s));
	while (!q.empty()) {
		PII u = q.top(); q.pop();
		if (vis[u.se]) continue;
		vis[u.se] = 1;
		//cout << u.se << " _>> " << u.fi << endl;
		for (int i = 0; i < g[u.se].size(); i++) {
			int v = g[u.se][i];
			if (u.fi + 1 < d[v]) {
				d[v] = u.fi + 1, q.push(mp(d[v], v));
				//cout << " upd " << v<< " _. " << d[v] << endl;
			}
		}
	}
//	puts("-----");
}

bool cmp(int x, int y) {
	return a[t[x]] - b[t[x]] < a[t[y]] - b[t[y]];
}


int ans;


int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++) scanf("%d", t + i), p1[i] = p2[i] = i;
	for (int i = 1, u, v; i <= m; i++)
		scanf("%d%d", &u, &v), g[u].pb(v), g[v].pb(u);
	dij(1, a), dij(n, b);
	sort(p1 + 1, p1 + 1 + k, cmp);
	ans = -2e9;
	int v = -2e9;
	for (int i = k; i; i--) {
		int j = t[p1[i]];
		ans = max(ans, min(a[n], a[j] + v + 1));
		v = max(v, b[j]);	
	}
	printf("%d\n", ans);
	return 0;
}