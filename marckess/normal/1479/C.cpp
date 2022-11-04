#include <bits/stdc++.h>

//#define endl '\n'
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

const int MX = 32;
int l, r, n, m, pos[MX], t, vis[MX];
vii adj[MX];

void go (int k) {
	adj[0].emplace_back(1, 1);
	n = 2;
	
	for (int i = 2, j = 1, cn = 1; cn < k; i++, j *= 2, cn *= 2, n++) {
		adj[0].emplace_back(i, j);
		adj[i].emplace_back(1, 1);
		
		if (cn + j <= k) {
			for (int x = 2, y = 1; x < i; x++, y *= 2)
				adj[i].emplace_back(x, y);
		} else {
			int d = k - cn - 1;
			for (int x = 2, y = 1, off = 1; x < i; x++, y *= 2)
				if (d & y) {
					adj[i].emplace_back(x, off);
					off += y;
				}
		}
	}
}

void dfs (int u) {
	vis[u] = 1;
	for (ii &v : adj[u])
		if (!vis[v.fi])
			dfs(v.fi);
	pos[u] = t--;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> l >> r;
	cout << "YES" << endl;
	
	go(r - l + 1);
	
	int s = 0;
	if (l > 1) {
		adj[n].emplace_back(0, l - 1);
		s = n;
		n++;
	}
	
	t = n;
	dfs(s);
	
	forn (i, n)
		m += adj[i].size();
	
	cout << n << " " << m << endl;
	forn (u, n)
		for (ii &v : adj[u])
			cout << pos[u] << " " << pos[v.fi] << " " << v.se << endl;
		
	return 0;
}