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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, m, res[MX], d[MX];
vii adj[MX];
queue<int> q;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	memset(res, -1, sizeof(res));
	memset(d, -1, sizeof(d));

	cin >> n >> m;

	while (m--) {
		int u, v, t;
		cin >> u >> v >> t;
		adj[v].emplace_back(u, t);
	}

	res[n] = d[n] = 0;
	q.push(n);

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (const ii &v : adj[u]) {
			if (res[v.fi] == -1) {
				res[v.fi] = 1 - v.se;
			} else if (res[v.fi] == v.se && d[v.fi] == -1) {
				d[v.fi] = d[u] + 1;
				q.push(v.fi);
			}
		}
	}

	cout << d[1] << endl;
	forn (i, n) cout << max(0, res[i + 1]);
	cout << endl;

	return 0;
}