#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005, mod = 1000000007;
int n, m, vis[12 * MX], cn;
ll res[12 * MX];
vii adj[12 * MX];

void add (int u, int v, int ind) {
	string s = to_string(ind);
	
	if (s.size() == 1) {
		adj[u].emplace_back(v, ind);
	} else {
		adj[u].emplace_back(cn++, s[0] - '0');
		for (int i = 1; i + 1 < s.size(); i++)
			adj[cn-1].emplace_back(cn++, s[i] - '0');
		adj[cn-1].emplace_back(v, s.back() - '0');
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	cn = n + 1;

	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		add(x, y, i);
		add(y, x, i);
	}

	vis[1] = 1;
	queue<vi> q;
	q.push({1});

	while (q.size()) {
		vi g = q.front();
		q.pop();

		for (int i = 0; i <= 9; i++) {
			vi ng;

			for (int u : g)
				for (ii &v : adj[u])
					if (v.se == i && !vis[v.fi]) {
						ng.pb(v.fi);
						vis[v.fi] = 1;
						res[v.fi] = (10 * res[u] + i) % mod;
					}

			if (ng.size())
				q.push(ng);
		}
	}

	for (int i = 2; i <= n; i++)
		cout << res[i] << endl;

	return 0;
}