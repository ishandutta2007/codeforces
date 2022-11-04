#include <bits/stdc++.h>

//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, d, u[MX], v[MX], in[MX];
int to[50*MX], nex[50*MX], ini[50*MX], sz = 0;
int dp[50*MX], scc[50*MX], st[50*MX], a[50*MX];
int low[50*MX], num[50*MX], vis[50*MX], cn = 0;
string sch[MX];

void add (int u, int v) {
	to[sz] = v, nex[sz] = ini[u], ini[u] = sz++;
}

void tarjan (int u) {
	low[u] = num[u] = ++cn;
	st[++sz] = u;
	vis[u] = 1;

	for (int e = ini[u]; e != -1; e = nex[e]) {
		int v = to[e];
		if (!num[v]) tarjan(v);
		if (vis[v]) low[u] = min(low[u], low[v]);
	}

	if (low[u] == num[u]) 
		while (1) {
			int v = st[sz--], x = v / d, y = v % d;
			vis[v] = 0, scc[v] = u;
			if (sch[x][y] == '1')
				a[u] += int(in[x] != u), in[x] = u;
			if (u == v) break;
		}
}

int dfs (int u) {
	int &res = dp[u];
	if (dp[u] != -1) return dp[u];
	res = 0;
	for (int e = ini[u]; e != -1; e = nex[e])
		res = max(res, dfs(to[e]));
	return res += a[u];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> d;

	memset(ini, -1, sizeof(ini));
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i];
		for (int k = 0; k < d; k++)
			add(u[i] * d + k, v[i] * d + (k + 1) % d);
	}

	for (int i = 1; i <= n; i++)
		cin >> sch[i];

	sz = -1;
	tarjan(d);

	sz = 0;
	memset(ini, -1, sizeof(ini));

	for (int i = 0; i < m; i++)
		for (int k = 0; k < d; k++) {
			int x = u[i] * d + k, y = v[i] * d + (k + 1) % d;
			if (scc[x] && scc[x] != scc[y])
				add(scc[x], scc[y]);
		}

	memset(dp, -1, sizeof(dp));
	cout << dfs(scc[d]) << endl;

	return 0;
}