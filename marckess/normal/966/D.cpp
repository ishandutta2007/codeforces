#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, m, u, v, d[MX], rec[MX];
vi adj[MX];
bitset<MX> bs;

void bfs () {
	memset(d, -1, sizeof(d));
	queue<int> q;
	q.push(1);
	d[1] = 0;

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u])
			if (d[v] == -1) {
				q.push(v);
				d[v] = d[u] + 1;
				rec[v] = u;
			}
	}	
}

ii bfs2 (int o) {
	memset(d, -1, sizeof(d));
	queue<int> q;
	q.push(o);
	d[o] = 0;

	while (q.size()) {
		int u = q.front();
		q.pop();

		if (d[u] == 2) {
			return {rec[u], u};
		}

		for (int v : adj[u])
			if (v != 1 && d[v] == -1) {
				q.push(v);
				d[v] = d[u]+1;
				rec[v] = u;
			}
	}

	assert(0);
}

int cn;
stack<int> st;
void dfs (int u) {
	bs[u] = 1;
	cn++;
	st.push(u);
	for (int v : adj[u])
		if (!bs[v] && v != 1)
			dfs(v);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	while (m--) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	bfs();

	if (d[n] > 0 && d[n] < 4) {
		cout << d[n] << endl;

		int u = n;
		vi res;

		while (1) {
			res.pb(u);
			if (u == 1) break;
			u = rec[u];
		}

		reverse(all(res));
		for (int x : res) cout << x << " ";
		cout << endl;
		return 0;
	}

	int ind = -1;
	for (int i = 1; i <= n; i++)
		if (d[i] == 2)
			ind = i;

	if (ind == -1) {
		
		for (int i = 2; i <= n; i++)
			if (!bs[i] && d[i] != -1) {
				cn = 0;
				dfs(i);

				while (st.size()) {
					int u = st.top();
					st.pop();

					if (adj[u].size() != cn) {
						ii r = bfs2(u);

						cout << 5 << endl;
						cout << "1 " << u << " " << r.fi << " " << r.se << " " << u << " " << n << endl;
						return 0;
					}
				}
			}

		cout << -1 << endl;
		return 0;
	}

	cout << 4 << endl;
	vi res = {n, 1};

	int u = ind;
	while (1) {
		res.pb(u);
		if (u == 1) break;
		u = rec[u];
	}

	reverse(all(res));
	for (int x : res) cout << x << " ";
	cout << endl;

	return 0;
}