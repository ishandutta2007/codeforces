#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 405, mod = 998244353;
int n, m, dis[MX][MX], cn[MX][MX], p[MX][MX], bs[MX];
vi adj[MX];

void bfs (vi s, int dis[], int cn[], int p[]) {
	forn (i, n)
		dis[i] = -1;
	
	queue<int> q;
	for (int u : s) {
		q.push(u);
		cn[u] = 1;
		dis[u] = 0;
		p[u] = 0;
	}
	
	while (q.size()) {
		int u = q.front();
		q.pop();
		
		for (int v : adj[u])
			if (dis[v] == -1) {
				cn[v] = 1;
				dis[v] = dis[u] + 1;
				p[v] = u;
				q.push(v);
			} else if (dis[u] + 1 == dis[v]) {
				cn[v]++;
			}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	
	cin >> n >> m;
	
	forn (i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	forn (i, n)
		bfs({i}, dis[i], cn[i], p[i]);
	
	forn (i, n) {
		forn (j, n) {
			if (i == j) {
				ll res = 1;
				forn (k, n)
					(res *= cn[i][k]) %= mod;
				cout << res << " ";
			} else {
				int v = j, f = 1;
				memset(bs, 0, sizeof(bs));
				
				while (v != i) {
					bs[v] = -1;
					if (cn[i][v] > 1)
						f = 0;
					v = p[i][v];
				}
				bs[v] = -1;
				
				if (!f) {
					cout << 0 << " ";
					continue;
				} 
		
				forn (u, n)
					for (int v : adj[u])
						if (bs[v] > -1)
							if (dis[i][u] + 1 == dis[i][v] && dis[j][u] + 1 == dis[j][v])
								bs[v]++;
			
				ll res = 1;
				forn (u, n)
					if (bs[u] > -1)
						(res *= bs[u]) %= mod;
				cout << res << " ";
			}
		}
		cout << endl;
	}
	
	return 0;
}