#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005, LG = 60;
int bt[LG], n, _n, adj[555][555], dis[555];
ll a[MX];

int bfs (int i, int j) {
	queue<int> q;
	memset(dis, -1, sizeof(dis));
	adj[i][j] = adj[j][i] = 0;
	q.push(i);
	dis[i] = 0;

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < n; v++)
			if (adj[u][v] && dis[v] == -1) {
				q.push(v);
				dis[v] = dis[u] + 1;
			}
	}

	adj[i][j] = adj[j][i] = 1;

	if (dis[j] != -1) return dis[j];
	return 1e9;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> _n;
	while (_n--) {
		cin >> a[n];
		if (a[n]) {
			forn (j, LG)
				if (a[n] & (1ll << j))
					bt[j]++;
			n++;
		}
	}

	if (*max_element(bt, bt+LG) >= 3) {
		cout << 3 << endl;
		return 0;
	}

	forn (i, n) forn(j, n) 
		if (i != j && (a[i] & a[j]))
			adj[i][j] = 1;

	int res = 1e9;
	forn (i, n) forn(j, n)
		if (i != j && (a[i] & a[j]))
			res = min(res, bfs(i, j) + 1);
		
	if (res == 1e9) cout << -1 << endl;
	else cout << res << endl;

	return 0;
}