#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <int, PII> PIP;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 4e18 + 3;
const int maxn = (1 << 20);
int n, m;
vector <int> queries[2 * maxn + 5][3];
int A[maxn], H[maxn], L[maxn];
ll res[maxn];
ll tab[2][maxn], help = 0;
ll pref[2][maxn];
int DL[2];
ll dist[maxn];
void dfs(int x, int type) {
	DL[type]++;
	tab[type][DL[type]] = dist[x];
	if (2 * x <= n) dist[2 * x] = dist[x] + L[2 * x], dfs(2 * x, type);
	if (2 * x + 1 <= n) dist[2 * x + 1] = dist[x] + L[2 * x + 1], dfs(2 * x + 1, type);
}

inline void napraw(int type) {
	sort(tab[type] + 1, tab[type] + DL[type] + 1);
	pref[type][0] = 0;
	for (int i=1; i<=DL[type]; ++i)
		pref[type][i] = pref[type][i-1] + tab[type][i];
}

void add(int query, int type) {
	int u = A[query], height = H[query] - dist[u];
	if (height <= 0) return;
	int x = 0, y = DL[type];
	while (x < y) {
		int mid = (x + y) / 2 + 1;
		if (tab[type][mid] > height) y = --mid;
		else x = mid;
	}

	res[query] += (ll)x * (ll)height - pref[type][x];
}

void solve(int x) {
	dist[x] = 0;
	if (x > n) return;
	DL[0] = DL[1] = 0;
	if (2 * x <= n) dist[2 * x] = L[2 * x], dfs(2 * x, 0);
	if (2 * x + 1 <= n) dist[2 * x + 1] = L[2 * x + 1], dfs(2 * x + 1, 1);
	napraw(0); napraw(1);
	for (auto u : queries[x][0]) {
		add(u, 1);
		//cout << "Adding: " << x << ' ' << A[u] << ' ' << dist[A[u]] << endl;
		if (H[u] >= dist[A[u]]) res[u] += H[u] - dist[A[u]];
	}
	
	for (auto u : queries[x][1]) {
		add(u, 0);
		//cout << "Adding 2 : "  << x << ' ' << u << endl;
		if (H[u] >= dist[A[u]]) res[u] += H[u] - dist[A[u]];
	}
	for (auto u : queries[x][2]) {
		add(u, 0); add(u, 1);
	}
	solve(2 * x);
	solve(2 * x + 1);
}

int main()
{
	int R = 1;
	boost;
	cin >> n >> m;
	while (R < n) R *= 2;
	FOR(i, 1, n-1) cin >> L[i + 1];
	FOR(i, 1, m) {
		cin >> A[i] >> H[i];
		res[i] = H[i];
		int x = A[i];
		queries[x][2].pb(i);
		while (x > 1) {
			int u = x / 2;
			if (2 * u == x) queries[u][0].pb(i);
			else queries[u][1].pb(i);
			x = u;
		}
	}
	
	solve(1);
	
	FOR(i, 1, m) cout << res[i] << "\n";
}