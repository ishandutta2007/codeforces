#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 10005;
int n, m, dis[11][MX], f, h[MX], k, p[MX], no[MX], mem[MX][7][1 << 6];
vi adj[MX];

void bfs (int s, int dis[]) {
	forr (i, 1, n)
		dis[i] = -1;
	dis[s] = 0;
	
	queue<int> q;
	q.push(s);
	
	while (q.size()) {
		int u = q.front();
		q.pop();
		
		for (int v : adj[u])
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
}

int dp (int i, int j, int mk) {
	if (i == f + 1) return k - __builtin_popcount(mk);
	
	int &res = mem[i][j][mk];
	if (res != -1) return res;
	res = dp(i + 1, k, mk);
	
	if (no[i]) return res;
	
	forn (l, k)
		if (~mk & (1 << l))
			if (dis[j][h[p[l]]] + dis[l][h[i]] == dis[j][h[i]])
				res = min(res, dp(i, l, mk | (1 << l)));
	
	return res;
}

void main_() {
	cin >> n >> m;
	
	forr (i, 1, n) {
		adj[i].clear();
	}
	
	forn (i, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	cin >> f;
	forr (i, 1, f) {
		cin >> h[i];
		no[i] = 0;
		memset(mem[i], -1, sizeof(mem[i]));
	}
	
	cin >> k;
	forn (i, k) {
		cin >> p[i];
		no[p[i]] = 1;
		bfs(h[p[i]], dis[i]);
	}
	
	bfs(1, dis[k]);
	
	cout << dp(1, k, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}